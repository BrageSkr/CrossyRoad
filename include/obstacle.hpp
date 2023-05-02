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

class obstacle {
public:

  void  obstacleGeometry(float w, float p, float pz) { //creates the obstacle and returns a mesh
        auto geometry = BoxGeometry::create(1, 1, w);
        auto material = MeshBasicMaterial::create();
        material->color.randomize();
        _mesh = Mesh::create(geometry, material);
        _mesh->position.x = p;
        _mesh->position.z = pz;
        _mesh->name = "obstacle";
        _mesh->geometry()->computeBoundingBox();

    }

    std::shared_ptr<Group> createObstalces(std::shared_ptr<Group> group) {
        for (int j = 0; j < 30; ++j) {
            for (int i = -50; i < 50; i += 8) {
                float width = math::randomInRange(minSize, maxSize);
                obstacle test;
                test.obstacleGeometry(width, (j * 2) + 2, i);
                if (j % 2 == 0) {
                    group->add(test.mesh());
                } else {
                    group->add(test.mesh());
                }
            }
        }

        return group;
    };

    std::shared_ptr<threepp::Mesh> mesh() {
        return _mesh;
    }




private:
   const  float maxSize = 8.0f;
   const  float minSize = 3.0f;
   std::shared_ptr<threepp::Mesh> _mesh;


};


#endif //EKSAMENOOP_OBSTACLE_HPP



