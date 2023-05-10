
#ifndef CROSSYROAD_OBSTACLE_HPP
#define CROSSYROAD_OBSTACLE_HPP

#include "threepp/threepp.hpp"
#include "threepp/extras/imgui/imgui_context.hpp"


using namespace threepp;

class obstacle {
public:
    void obstacleGeometry(float w, float p, float pz);

    void createObstacles(std::shared_ptr<threepp::Group> group1, std::shared_ptr<threepp::Group> group2);

    void
    updateHitbox(std::shared_ptr<threepp::Group> group1, std::shared_ptr<threepp::Group> group2, bool &hasCollision,
                 std::shared_ptr<threepp::Mesh> player);

    std::shared_ptr<threepp::Mesh> mesh();

private:
    const float maxSize = 7.0f;
    const float minSize = 3.0f;
    const int  distanceBetweenX = 8;
    const int distanceBetweenZ = 3;
    const int rowX = 50;
    const int rowZ = 30;
    std::shared_ptr<threepp::Mesh> _mesh;
};


#endif //CROSSYROAD_OBSTACLE_HPP



