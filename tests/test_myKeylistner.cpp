
#include "myKeylistener.hpp"
#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>


TEST_CASE("test_keylistner") {
    keyInput test;
    bool value = test.right;


    CHECK(value == false);
}