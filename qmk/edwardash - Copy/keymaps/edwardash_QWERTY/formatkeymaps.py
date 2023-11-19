import dataclasses
import functools
import itertools

import regex as re
import pyparsing
import pathlib
from contextlib import contextmanager

sample_keymap = """
        XXXXXXX,        XXXXXXX,        XXXXXXX,          XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,         XXXXXXX,         XXXXXXX,        XXXXXXX,
        XXXXXXX,        XXXXXXX,        XXXXXXX,          XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,         XXXXXXX,         XXXXXXX,        XXXXXXX,
        XXXXXXX,        XXXXXXX,        XXXXXXX,          XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,         XXXXXXX,         XXXXXXX,        XXXXXXX,
                                                          XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
                                        XXXXXXX,          XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,         XXXXXXX,         XXXXXXX
"""

LEADING_SPACING_LENGTH = 8
SPACING_LENGTH = 24


@dataclasses.dataclass
class Key:
    is_key = True
    row: int
    column: int
    key_code: str

    def __post_init__(self):
        self.target_index = self.column * SPACING_LENGTH + LEADING_SPACING_LENGTH


@dataclasses.dataclass
class Space(Key):
    is_key = False


KEY = Key
___ = Space

ideal_keymap = [
    [KEY, KEY, KEY, KEY, KEY, KEY, KEY, KEY, KEY, KEY],
    [KEY, KEY, KEY, KEY, KEY, KEY, KEY, KEY, KEY, KEY],
    [KEY, KEY, KEY, KEY, KEY, KEY, KEY, KEY, KEY, KEY],
    [___, ___, ___, KEY, KEY, KEY, KEY, ___, ___, ___],
    [___, KEY, KEY, KEY, KEY, KEY, KEY, KEY, KEY, ___],
]


def yield_ideal_keys():
    for i, row in enumerate(ideal_keymap):
        for j, key in enumerate(row):
            if key.is_key:
                yield functools.partial(key, i, j)


@contextmanager
def load_layout_file(filename='layout.c'):
    file_path = pathlib.Path(__file__).parent.joinpath(filename)
    with open(file_path, 'r') as f:
        yield f.read()


class Layout:

    def __init__(self, match):
        self.layout_name, raw_layout = match.label, match.expression
        self.keycodes = self.split_outside_brackets(raw_layout[1:-1])

    @staticmethod
    def split_outside_brackets(s):

        def _split_outside_brackets():
            depth = 0
            last_split = 0

            for idx, char in enumerate(s):
                if char == '(':
                    depth += 1
                elif char == ')':
                    depth -= 1
                elif char == ',' and depth == 0:
                    yield s[last_split:idx].strip()
                    last_split = idx + 1
            yield s[last_split:].strip()

        return tuple(
            x for x in _split_outside_brackets()
            if x
        )


def find_all_layouts(file):
    # Define the parser
    label = pyparsing.Word(pyparsing.alphanums + "_").setResultsName("label")
    layout_expression = pyparsing.originalTextFor(pyparsing.nestedExpr()).setResultsName("expression")
    layout_parser = "[" + label + "]" + pyparsing.Optional(pyparsing.White()) + "=" + pyparsing.Optional(pyparsing.White()) + pyparsing.Literal("LAYOUT") + layout_expression

    for match in layout_parser.searchString(file):
        yield Layout(match)


def main():
    with load_layout_file() as file:
        for layout in find_all_layouts(file):
            keys = []
            for key_template, keycode in itertools.zip_longest(yield_ideal_keys(),
                                                               layout.keycodes):
                assert key_template and keycode
                key = key_template(keycode)
                keys.append(key)

            rows = [tuple(x[1]) for x in itertools.groupby(keys, key=lambda x: x.row)]

            print(f"[{layout.layout_name}] = LAYOUT(")

            for i, row in enumerate(rows, start=1):
                str_row = " " * LEADING_SPACING_LENGTH
                for j, key in enumerate(row, start=1):
                    str_row += ' ' * max(key.target_index - len(str_row), 0)
                    str_row += key.key_code
                    if (i, j) != (len(rows), len(row)):
                        # Don't add a comma to the last key of the last row per layouts
                        str_row += ','
                print(str_row)

            print("),")

            print('\n' * 4)


if __name__ == "__main__":
    main()
