
#include "myKeylistener.hpp"

#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>


TEST_CASE("Test myKeyListener") {

    myKeyListener listener;


    KeyEvent keyUp(87, 0, 0);  // 'w' key up
    listener.onKeyPressed(keyUp);
    CHECK(listener.getKeyInput().up == true);

    KeyEvent keyDown(83, 0, 0);  // 's' key down
    listener.onKeyPressed(keyDown);
    CHECK(listener.getKeyInput().down == true);

    KeyEvent keyRight(68, 0, 0);  // 'd' key right
    listener.onKeyPressed(keyRight);
    CHECK(listener.getKeyInput().right == true);

    KeyEvent keyLeft(65, 0, 0);  // 'a' key left
    listener.onKeyPressed(keyLeft);
    CHECK(listener.getKeyInput().left == true);

    KeyEvent keyReset(82, 0, 0);  // 'r' key reset
    listener.onKeyPressed(keyReset);
    CHECK(listener.getKeyInput().reset == true);


    listener.onKeyReleased(keyUp);
    CHECK(listener.getKeyInput().up == false);

    listener.onKeyReleased(keyDown);
    CHECK(listener.getKeyInput().down == false);

    listener.onKeyReleased(keyRight);
    CHECK(listener.getKeyInput().right == false);

    listener.onKeyReleased(keyLeft);
    CHECK(listener.getKeyInput().left == false);

    listener.onKeyReleased(keyReset);
    CHECK(listener.getKeyInput().reset == false);
}
