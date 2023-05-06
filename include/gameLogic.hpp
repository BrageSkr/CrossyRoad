
#ifndef CROSSYROAD_GAMELOGIC_HPP
#define CROSSYROAD_GAMELOGIC_HPP

#include "threepp/threepp.hpp"
#include "threepp/extras/imgui/imgui_context.hpp"

using namespace threepp;

class GameLogic {
public:
    void updateGame(std::shared_ptr<threepp::Mesh> player, std::shared_ptr<threepp::Group> group1,
                    std::shared_ptr<threepp::Group> group2, float dt,TextHandle& textHandle,bool hasCollision);

    void setTextHandle (TextHandle& textHandle);
private:
    int group1SpeedDirection = 1;
    int group2SpeedDirection = 1;
    int maxPositionZ = 20;
    int minPositionZ = -20;
    int maxPositionX = 60;
    int minPositionX = 0;
    int distance = 0;
    int score = 0;
    int highestScore = 0;
    int totalDistance = 0;
};

#endif //CROSSYROADGAMELOGIC_HPP
