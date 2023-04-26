
#define CATCH_CONFIG_MAIN

#include "sphere.hpp"
#include "myKeylistener.hpp"
#include <catch2/catch.hpp>


TEST_CASE("test sphere") {
    keyInput test;
    bool value = test.right;

    CHECK(value == false);
}