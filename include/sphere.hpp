#ifndef EKSAMENOOP_SPHERE_HPP
#define EKSAMENOOP_SPHERE_HPP

#include "threepp/threepp.hpp"
#include "threepp/extras/imgui/imgui_context.hpp"
#include <array>
#include <string>
#include <iostream>
#include <myKeylistener.hpp>


using namespace threepp;

class sphere {
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

    void update(float dt, const keyInput &input) {
        if (input.up) {
            move_forwards(dt);
        }
        if (input.down) {
            move_backwards(dt);
        }
        if (input.right) {
            move_right(dt);
        }
        if (input.left) {
            move_left(dt);
        }
        if (input.reset) {
            reset();
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
    const float speed = 4.f;


};


#endif //EKSAMENOOP_SPHERE_HPP
