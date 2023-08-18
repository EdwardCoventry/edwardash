import sys
import os
import re
import glob
import xml.etree.ElementTree as ET

def scale_svg_content(svg_content):
    # Define scaling factor
    scaling_factor = 0.00000377953

    # Parse the SVG content using ElementTree
    root = ET.fromstring(svg_content)

    # return ET.tostring(root, encoding="unicode")

    # Adjust the viewBox based on the width and height attributes
    width = root.get("width")
    height = root.get("height")

    if width and height:
        root.set('viewBox', f'0 0 {width} {height}')

    # Scale the stroke-width in the style attributes of <g> tags
    for g_tag in root.findall(".//{*}g"):
        style_content = g_tag.get('style', '')
        style_content = re.sub(r'stroke-width:(\d+\.?\d*)', lambda x: f'stroke-width:{float(x.group(1)) * scaling_factor}', style_content)
        g_tag.set('style', style_content)

    # Scale the path data in path tags
    for path_tag in root.findall(".//{*}path"):
        path_data = path_tag.get('d', '')
        path_data = re.sub(r'(\d+\.?\d*)', lambda x: str(float(x.group(1)) * scaling_factor), path_data)
        path_tag.set('d', path_data)

    # Remove namespaces
    for elem in root:
        if '}' in elem.tag:
            elem.tag = elem.tag.split('}', 1)[1]  # Strip off the namespace

    # Convert the modified XML tree back to a string
    new_svg_content = ET.tostring(root, encoding="unicode")

    # Hacky add the namespace back to the <g> tags
    new_svg_content = new_svg_content.replace('<g style', '<ns0:g style')
    new_svg_content = new_svg_content.replace('</g>', '</ns0:g>')



    empty_style_tag = """<ns0:g style="">
</ns0:g>
"""

    new_svg_content = new_svg_content.replace(
        empty_style_tag, "")
    new_svg_content = new_svg_content.replace("<ns0:g>\n</ns0:g>", "")


    # Parse the SVG content using ElementTree
    root = ET.fromstring(new_svg_content)


    new_svg_content = ET.tostring(root, encoding="unicode")

    new_svg_content = new_svg_content.replace("ns0:", '')
    new_svg_content = new_svg_content.replace(":ns0", '')

    return new_svg_content



def process_file(file_path):
    # Check if it's an SVG file
    if not file_path.lower().endswith('.svg'):
        print(f"Invalid SVG file: {file_path}")
        return

    # Read the SVG content
    with open(file_path, 'r', encoding='utf-8') as f:
        svg_content = f.read()

    # Scale the SVG content
    scaled_svg_content = scale_svg_content(svg_content)

    # Define the output file name
    script_dir = os.path.dirname(os.path.abspath(__file__))
    scaled_dir = os.path.join(script_dir, 'scaled')
    if not os.path.exists(scaled_dir):
        os.mkdir(scaled_dir)

    base_name = os.path.basename(file_path)
    output_file_name = os.path.join(scaled_dir, base_name)

    if os.path.exists(output_file_name):
        print(f"Existing file {output_file_name} will be overwritten.")

    # Save the scaled SVG content
    with open(output_file_name, 'w', encoding='utf-8') as f:
        f.write(scaled_svg_content)

    print(f"File saved as {output_file_name}")

def main(paths=None):

    paths = paths or sys.argv[1:]

    # Check if file path is provided
    if not paths:
        print("Please specify the SVG file(s) or use wildcards like '*'.")
        return

    # Expand the wildcard matches if present or use the direct file path
    files = []
    for path in paths:
        matched_files = glob.glob(path)
        if matched_files:
            files.extend(matched_files)
        else:
            files.append(path)

    # Process each file
    for file_path in files:
        print(file_path)
        process_file(file_path)

if __name__ == "__main__":
    main()
