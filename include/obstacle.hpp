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


class obstacle{
public:


    void change_dimensions(float l_1,float w_1){
        width = w_1;
        length = l_1;
    }

    auto create_geometry(float length,float height,float width, float pos,float pz);
private:

    float width = 0;
    float height = 1;
    float length = 0;
    float pos = 0;
};

std::array<float,3> return_color(){
    float random_red = math::randomInRange(0.f,1.f);
    float random_green = math::randomInRange(0.f,1.f) ;
    float random_blue = math::randomInRange(0.f,1.f);
    std::array<float,3> random_colors = {random_red, random_green, random_blue};
    return random_colors;
};
auto obstacle::create_geometry (float l,float h,float w, float p,float pz){
    auto geometry = BoxGeometry::create(l,h,w);
    auto material = MeshBasicMaterial::create();
    std::array<float,3>random_color  = return_color();
    material->color = Color(random_color[0],random_color[1],random_color[2]);
    auto mesh = Mesh::create(geometry, material);
    mesh->position.x = p;
    mesh->position.z= pz;

    return mesh;
}

#endif //EKSAMENOOP_OBSTACLE_HPP



