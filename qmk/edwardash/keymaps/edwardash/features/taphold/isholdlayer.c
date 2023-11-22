
#include "layermap.c"


const size_t defined_hold_layers_count = sizeof(defined_hold_layers) / sizeof(defined_hold_layers[0]);

bool layer_in_hold_layers(uint8_t layer) {
    for (size_t i = 0; i < defined_hold_layers_count; ++i) {
        if (defined_hold_layers[i] == layer) {
            return true;
        }
    }
    return false;
}