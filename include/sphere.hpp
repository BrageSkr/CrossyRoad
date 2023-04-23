#ifndef EKSAMENOOP_SPHERE_HPP
#define EKSAMENOOP_SPHERE_HPP

#include "threepp/threepp.hpp"
#include "threepp/extras/imgui/imgui_context.hpp"
#include <array>
#include <string>
#include <iostream>

using namespace threepp;

struct wasd {  // a struct that describes the keyinput as a boolean with the name of direction
    bool left = false;
    bool right = false;
    bool up = false;
    bool down = false;
};

class sphere : public KeyListener {
public:

    sphere(float position_x) { //generates the sphere with a starting position as a constructor
        auto geometry = SphereGeometry::create(0.1f, 20, 20);
        auto material = MeshBasicMaterial::create();
        material->color = Color::red;
        _mesh = Mesh::create(geometry, material);
        _mesh->position.x = position_x;
        _mesh->name = "sphere";
        _mesh->geometry()->computeBoundingSphere();

    }

    std::shared_ptr<threepp::Mesh> mesh() {
        return _mesh;  //returns the _mesh as a shared pointer
    }

    void onKeyPressed(
            KeyEvent evt) override { //keylistner that monitors button presses, and changes the boolean for direction accordingly

        if (evt.key == 87) {
            wasd_.up = true;
        } else if (evt.key == 83) {
            wasd_.down = true;
        } else if (evt.key == 68) {
            wasd_.right = true;
        } else if (evt.key == 65) {
            wasd_.left = true;
        }
    };

    void onKeyReleased(
            KeyEvent evt) override { //keylistner that monitors if a button is released, and changes the boolean for direction accordingly
        if (evt.key == 87) {
            wasd_.up = false;
        } else if (evt.key == 83) {
            wasd_.down = false;
        } else if (evt.key == 68) {
            wasd_.right = false;
        } else if (evt.key == 65) {
            wasd_.left = false;
        }
    };

    void update(float dt) { //an update function that calls spesific movments functions

        if (wasd_.up) {
            move_forwards(dt);
        }
        if (wasd_.down) {
            move_backwards(dt);
        }
        if (wasd_.right) {
            move_right(dt);
        }
        if (wasd_.left) {
            move_left(dt);
        }
    };

    void move_forwards(float dt) {
        _mesh->position.x += speed * dt;
    };

    void move_backwards(float dt) {
        _mesh->position.x += -speed * dt;
    };

    void move_right(float dt) {
        _mesh->position.z += speed * dt;
    };

    void move_left(float dt) {
        _mesh->position.z += -speed * dt;
    };

    void reset() {
        _mesh->position.x = 0;
        _mesh->position.z = 0;

    }

private:
    std::shared_ptr<threepp::Mesh> _mesh;
    float speed = 4.f;
    wasd wasd_;
};


#endif //EKSAMENOOP_SPHERE_HPP
