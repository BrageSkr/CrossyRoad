
#define CATCH_CONFIG_MAIN
#include "myKeylistener.hpp"
#include "sphere.hpp"
#include <catch2/catch.hpp>


TEST_CASE("test sphere") {
    struct keyInput test;
    bool value = test.right;

    CHECK(value == false);
}