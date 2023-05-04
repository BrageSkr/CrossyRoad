//
// Created by Brage Skrettingland on 25/02/2023.
//
#ifndef EKSAMENOOP_OBSTACLE_HPP
#define EKSAMENOOP_OBSTACLE_HPP

#include "threepp/threepp.hpp"
#include "threepp/extras/imgui/imgui_context.hpp"


using namespace threepp;

class obstacle {
public:
    void obstacleGeometry(float w, float p, float pz);
    void createObstacles(std::shared_ptr<threepp::Group> group1, std::shared_ptr<threepp::Group> group2);
    void updateHitbox(std::shared_ptr<threepp::Group> group1, std::shared_ptr<threepp::Group> group2, bool& hasCollision, threepp::Sphere playerWorldBoundingSphere);
    std::shared_ptr<threepp::Mesh> mesh();

private:
    const float maxSize = 7.5f;
    const float minSize = 3.0f;
    std::shared_ptr<threepp::Mesh> _mesh;
};


#endif //EKSAMENOOP_OBSTACLE_HPP



