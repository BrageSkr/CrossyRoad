#ifndef EKSAMENOOP_SPHERE_HPP
#define EKSAMENOOP_SPHERE_HPP

#include "threepp/threepp.hpp"
#include "threepp/extras/imgui/imgui_context.hpp"
#include "myKeylistener.hpp"


using namespace threepp;

class sphere {
public:
    sphere(float position_x);

    std::shared_ptr<threepp::Mesh> mesh();

    void update(float dt, const keyInput &input, int hexColor, bool hasCollision);

    void move_forwards(float dt);

    void move_backwards(float dt);

    void move_right(float dt);

    void move_left(float dt);

    void reset();

    void changeColor();

    void updateColor(int hexColor);


private:
    std::shared_ptr<threepp::Mesh> _mesh;
    const float speed = 6.f;
    int newColor = 0xFF0000;
    std::shared_ptr<threepp::MeshBasicMaterial> meshBasicMaterial;
};


#endif //EKSAMENOOP_SPHERE_HPP
