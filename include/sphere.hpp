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


class sphere{
public:
    auto create_geometry(float p);
private:

};

auto sphere::create_geometry (float p) {
    auto geometry = SphereGeometry::create(0.75f,20,20);
    auto material = MeshBasicMaterial::create();
    std::array<float, 3> random_color = return_color();
    material->color = Color::red;
    //material->wireframe = true;
    auto mesh = Mesh::create(geometry, material);
    mesh->position.x = p;
    return mesh;
}

#endif //EKSAMENOOP_SPHERE_HPP
