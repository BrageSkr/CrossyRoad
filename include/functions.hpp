#ifndef EKSAMENOOP_FUNCTIONS_HPP
#define EKSAMENOOP_FUNCTIONS_HPP

#include "threepp/extras/imgui/imgui_context.hpp"

unsigned int updateHexColor(ImColor color) {
    unsigned int hexColor = ((unsigned int) (color.Value.x * 255.0f) << 16) |
                            ((unsigned int) (color.Value.y * 255.0f) << 8) |
                            ((unsigned int) (color.Value.z * 255.0f));
    return hexColor;
}

#endif //EKSAMENOOP_FUNCTIONS_HPP
