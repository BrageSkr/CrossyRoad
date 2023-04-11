
#define CATCH_CONFIG_MAIN

#include "sphere.hpp"
#include <catch2/catch.hpp>


TEST_CASE("test sphere") {
    wasd test;
    bool value = test.right;

    CHECK(value == false);
}