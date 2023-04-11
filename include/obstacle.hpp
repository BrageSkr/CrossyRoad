//
// Created by Brage Skrettingland on 25/02/2023.
//
#ifndef EKSAMENOOP_OBSTACLE_HPP
#define EKSAMENOOP_OBSTACLE_HPP

#include "threepp/threepp.hpp"
#include "threepp/extras/imgui/imgui_context.hpp"
#include <array>
#include <string>
#include <iostream>

using namespace threepp;

std::array<float, 3> return_color() {
    float random_red = math::randomInRange(0.f, 1.f);
    float random_green = math::randomInRange(0.f, 1.f);
    float random_blue = math::randomInRange(0.f, 1.f);
    std::array<float, 3> random_colors = {random_red, random_green, random_blue};
    return random_colors;
};

class obstacle {
public:

    obstacle(float w, float p, float pz) { //creates the obstacle and returns a mesh 
        auto geometry = BoxGeometry::create(1, 1, w);
        auto material = MeshBasicMaterial::create();
        std::array<float, 3> random_color = return_color();
        material->color = Color(random_color[0], random_color[1], random_color[2]);
        _mesh = Mesh::create(geometry, material);
        _mesh->position.x = p;
        _mesh->position.z = pz;
        _mesh->name = "obstacle";


    }

    std::shared_ptr<threepp::Mesh> mesh() {
        return _mesh;
    }


private:
    std::shared_ptr<threepp::Mesh> _mesh;

};


#endif //EKSAMENOOP_OBSTACLE_HPP



