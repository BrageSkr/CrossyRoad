#include "../include/gameLogic.hpp"

void GameLogic::updateGame(std::shared_ptr<threepp::Mesh> player, std::shared_ptr<threepp::Group> group1,
                           std::shared_ptr<threepp::Group> group2, float dt, TextHandle& textHandle, bool hasCollision) {
    group2->position.z += math::randomInRange(3.f, 5.f) * dt * group2SpeedDirection;
    group1->position.z += math::randomInRange(2.f, 3.f) * dt * group1SpeedDirection;

    if (group1->position.z >= maxPositionZ) {
        group1SpeedDirection = -1;
    }
    if (group2->position.z >= maxPositionZ) {
        group2SpeedDirection = -1;
    }
    if (group1->position.z <= minPositionZ) {
        group1SpeedDirection = 1;
    }
    if (group2->position.z <= minPositionZ) {
        group2SpeedDirection = 1;
    }

    if (player->position.x > maxPositionX) {
        totalDistance += maxPositionX;
        player->position.x = minPositionX;
    }
    if (player->position.x < minPositionX) {
        player->position.x = minPositionX;
    }

    if (player->position.z >= maxPositionZ) {

    }
    if (player->position.z <= minPositionZ) {
        player->position.z = minPositionZ;

    }
    if (hasCollision){
        totalDistance = 0;
    }

    distance = player->position.x + totalDistance;
    score = distance / 3;

    if (score > highestScore) {
        highestScore = score;
    }
    if (score > highestScore) {
        highestScore = score;
    }
    setTextHandle(textHandle);

}

void GameLogic::setTextHandle (TextHandle& textHandle){

    textHandle.setText("Hi-Score: " + std::to_string(highestScore) + " Score: " + std::to_string(score));
}
