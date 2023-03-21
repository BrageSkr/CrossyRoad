//
// Created by Brage Skrettingland on 04/03/2023.
//

#ifndef EKSAMENOOP_SPHERE_HPP
#define EKSAMENOOP_SPHERE_HPP

#include "threepp/threepp.hpp"
#include "threepp/extras/imgui/imgui_context.hpp"
#include <array>
#include <string>
#include <iostream>
using namespace threepp;

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

    void move(float dt) {
        _mesh->position.x += 0.5f * dt;
        _mesh->position.z += 0.5f * dt;
    }
    void onKeyPressed(KeyEvent evt, float dt)  {

            if (evt.key == 265 ) {
                _mesh->position.x += 0.5f *dt;
            }
            if (evt.key == 264 ) {
                _mesh->position.x += -0.5f *dt;
            }
            if (evt.key == 263 ) {
                _mesh->position.z += 0.5f *dt;;
            }
            if (evt.key == 262 ) {
                _mesh->position.x += -0.5f *dt;;
            }}



private:
  std::shared_ptr  <threepp:: Mesh> _mesh;
};






#endif //EKSAMENOOP_SPHERE_HPP
