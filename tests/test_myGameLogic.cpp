#include "gameLogic.hpp"
#include "sphere.hpp"
#include "threepp/extras/imgui/imgui_context.hpp"
#include "threepp/threepp.hpp"
#include "functions.hpp"

#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>


TEST_CASE("UpdateHexColor test") {
    int refrenceColor = 0xFF0000;
    ImColor color(1.0, 0.0f, 0.0f, 1.0f);
    unsigned int hexColor = updateHexColor(color);


    CHECK(hexColor == refrenceColor);
}

TEST_CASE("GameLogic updateGame movement and score") {
    sphere player(0);
    auto playerTest = player.mesh();
    auto group1 = Group::create();
    auto group2 = Group::create();
    float dt = 1.0f;
    Canvas canvas;
    GLRenderer renderer(canvas);
    auto &textHandle = renderer.textHandle();

    bool hasCollision = false;

    GameLogic gameLogic;
    gameLogic.updateGame(playerTest, group1, group2, dt, textHandle, hasCollision);

    CHECK(group1->position.z != 0.0f);
    CHECK(group2->position.z != 0.0f);


    playerTest->position.x = 10*3;
    gameLogic.updateGame(playerTest, group1, group2, dt, textHandle, hasCollision);
    int score = gameLogic.getScore();
    CHECK(score == playerTest->position.x/3);

}


