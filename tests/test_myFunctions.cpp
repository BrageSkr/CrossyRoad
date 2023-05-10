
#include "threepp/extras/imgui/imgui_context.hpp"

#include "functions.hpp"

#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>


TEST_CASE("UpdateHexColor test") {
    int refrenceColor = 0xFF0000;
    ImColor color(1.0, 0.0f, 0.0f, 1.0f);
    unsigned int hexColor = updateHexColor(color);


    CHECK(hexColor == refrenceColor);
}


