
#include "sphere.hpp"

#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>


TEST_CASE("test sphere") {
sphere player(0);
int color = 0x008B8B;
player.updateColor(color);
int newColor = player.getColor();


    CHECK(color == newColor);
}