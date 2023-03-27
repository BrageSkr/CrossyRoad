
#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include "sphere.hpp"

TEST_CASE("test sphere") {
    wasd test;
    bool value = test.right;

    CHECK(value == false);
}