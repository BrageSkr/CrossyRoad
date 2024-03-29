#ifndef CROSSYROAD_SPHERE_HPP
#define CROSSYROAD_SPHERE_HPP

#include "threepp/threepp.hpp"
#include "myKeylistener.hpp"


using namespace threepp;

class sphere {
public:
    sphere(float position_x);

    std::shared_ptr<threepp::Mesh> mesh();

    void update(float dt, const keyInput &input, int hexColor, bool hasCollision);

    void moveForwards(float dt);

    void moveBackwards(float dt);

    void moveRight(float dt);

    void moveLeft(float dt);

    void reset();

    void changeColor();

    void updateColor(int hexColor);


private:
    std::shared_ptr<threepp::Mesh> _mesh;
    const float speed = 6.f;
    int newColor = 0xFF0000;
    std::shared_ptr<threepp::MeshBasicMaterial> meshBasicMaterial;
};


#endif //CROSSYROAD_SPHERE_HPP
