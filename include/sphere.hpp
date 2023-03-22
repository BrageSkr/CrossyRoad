#ifndef EKSAMENOOP_SPHERE_HPP
#define EKSAMENOOP_SPHERE_HPP

#include "threepp/threepp.hpp"
#include "threepp/extras/imgui/imgui_context.hpp"
#include <array>
#include <string>
#include <iostream>
using namespace threepp;

struct wasd {
    bool left = false;
    bool right = false;
    bool up = false;
    bool down = false;
};

class sphere : public KeyListener {
public:

    sphere(float p) {
        auto geometry = SphereGeometry::create(0.75f, 20, 20);
        auto material = MeshBasicMaterial::create();
        material->color = Color::red;
        _mesh = Mesh::create(geometry, material);
        _mesh->position.x = p;

    }
    std::shared_ptr<threepp::Mesh> mesh() {
        return _mesh;
    }
    void onKeyPressed(KeyEvent evt) override  {

        if (evt.key == 87) {
            wasd_.up = true;
        } else if (evt.key == 83) {
            wasd_.down = true;
        } else if (evt.key == 68) {
            wasd_.right = true;
        } else if (evt.key == 65) {
            wasd_.left = true;
        }};
    void onKeyReleased(KeyEvent evt) override {
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
    void update(float dt) {

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
        }};

void move_forwards(float dt){
    _mesh->position.x+= speed *dt;
};
void move_backwards(float dt){
        _mesh->position.x+= -speed *dt;
    };
void move_right(float dt){
        _mesh->position.z+= speed *dt;
    };
void move_left(float dt){
        _mesh->position.z+= -speed *dt;
    };
private:
  std::shared_ptr  <threepp:: Mesh> _mesh;
  float speed = 3.f;
  wasd wasd_;
};


#endif //EKSAMENOOP_SPHERE_HPP
