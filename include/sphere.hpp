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

enum class Direction {
    LEFT,
    RIGHT,
    UP,
    DOWN
};


class sphere{
public:

sphere(float p)
     {
        auto geometry = SphereGeometry::create(0.75f,20,20);
        auto material = MeshBasicMaterial::create();
        material->color = Color::red;
        _mesh = Mesh::create(geometry, material);
        _mesh->position.x = p;

    }

    std::shared_ptr  <threepp:: Mesh> mesh(){
    return _mesh;
}
    void move (float dt){
        _mesh->position.x += 5.f *dt;
        _mesh->position.z += 5.f *dt;

    }
private:
  std::shared_ptr  <threepp:: Mesh> _mesh;
};


#endif //EKSAMENOOP_SPHERE_HPP
