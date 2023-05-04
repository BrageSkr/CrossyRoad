//
// Created by Brage Skrettingland on 03/05/2023.
//

#ifndef EKSAMENOOP_GAMELOGIC_HPP
#define EKSAMENOOP_GAMELOGIC_HPP
#include "threepp/threepp.hpp"
#include "threepp/extras/imgui/imgui_context.hpp"
using namespace threepp;
unsigned int updateHexColor(ImColor color) {
    unsigned int hexColor = ((unsigned int) (color.Value.x * 255.0f) << 16) |
                            ((unsigned int) (color.Value.y * 255.0f) << 8) |
                            ((unsigned int) (color.Value.z * 255.0f));
    return hexColor;
}
class GameLogic {
public:
    void updateGame (std::shared_ptr<threepp::Mesh> player,std::shared_ptr<threepp::Group> group1,std::shared_ptr<threepp::Group> group2, float dt){
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
            player->position.x = minPositionX;
        }
        if (player->position.x < minPositionX) {
            player->position.x = minPositionX;
        }

        if (player->position.z >= maxPositionZ) {
            player->position.z = maxPositionZ;
        }
        if (player->position.z <= minPositionZ) {
            player->position.z = minPositionZ;
        }
    }
    

private:
    int group1SpeedDirection = 1;
    int group2SpeedDirection = 1;
    int maxPositionZ = 20;
    int minPositionZ = -20;
    int maxPositionX = 60;
    int minPositionX = 0;
};
#endif //EKSAMENOOP_GAMELOGIC_HPP
