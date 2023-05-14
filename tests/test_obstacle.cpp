#include "obstacle.hpp"
#include "sphere.hpp"
#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
TEST_CASE("obstacleGeometry sets mesh properties correctly") {
    obstacle testObstacle;
    testObstacle.obstacleGeometry(2.0f, 0.0f, 0.0f);
    auto mesh = testObstacle.mesh();

    CHECK(mesh->position.x == 0.0f);
    CHECK(mesh->position.y == 0.0f);
    CHECK(mesh->position.z == 0.0f);

    
}



TEST_CASE("updateHitbox detects collision with obstacles") {
obstacle testObstacle;
auto group1 = Group::create();
auto group2 = Group::create();

testObstacle.createObstacles(group1, group2);
sphere sphere(0);
auto player = sphere.mesh();

bool hasCollision = false;

    player->position.x = group1->children[0]->position.x;
    player->position.z = group1->children[0]->position.z;
    hasCollision = false;
testObstacle.updateHitbox(group1, group2, hasCollision, player);

CHECK(hasCollision == true);
}

