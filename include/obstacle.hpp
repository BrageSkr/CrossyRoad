//
// Created by Brage Skrettingland on 25/02/2023.
//
#ifndef EKSAMENOOP_OBSTACLE_HPP
#define EKSAMENOOP_OBSTACLE_HPP

#include "threepp/threepp.hpp"
#include "threepp/extras/imgui/imgui_context.hpp"


using namespace threepp;

class obstacle {
public:

    void obstacleGeometry(float w, float p, float pz) { //creates the obstacle and returns a mesh
        auto geometry = BoxGeometry::create(1, 1, w);
        auto material = MeshBasicMaterial::create();
        material->color.randomize();
        _mesh = Mesh::create(geometry, material);
        _mesh->position.x = p;
        _mesh->position.z = pz;
        _mesh->name = "obstacle";
        _mesh->geometry()->computeBoundingBox();

    }

    void createObstacles(std::shared_ptr<threepp::Group> group1, std::shared_ptr<threepp::Group> group2) {
        for (int j = 0; j < 30; ++j) {
            for (int i = -50; i < 50; i += 8) {
                float width = math::randomInRange(minSize, maxSize);
                obstacle test;
                test.obstacleGeometry(width, (j * 3) + 2, i);
                if (j % 2 == 0) {
                    group2->add(test.mesh());
                } else {
                    group1->add(test.mesh());
                }
            }
        }
    }
    void updateHitbox (std::shared_ptr<threepp::Group> group1, std::shared_ptr<threepp::Group> group2,bool &hasCollision,threepp::Sphere playerWorldBoundingSphere){

        for (auto &obstacle: group1->children) {
            auto obstacleBoundingBox = obstacle->geometry()->boundingBox; // get bounding box of obstacle
            auto obstacleWorldBoundingBox = obstacleBoundingBox->clone().applyMatrix4(
                    *obstacle->matrixWorld);// compute the world-space bounding box of the obstacle

            if (playerWorldBoundingSphere.intersectsBox(obstacleWorldBoundingBox)) {
                hasCollision = true;
            }
        }
        for (auto &obstacle: group2->children) {
            auto obstacleBoundingBox = obstacle->geometry()->boundingBox; // get bounding box of obstacle
            auto obstacleWorldBoundingBox = obstacleBoundingBox->clone().applyMatrix4(
                    *obstacle->matrixWorld);// compute the world-space bounding box of the obstacle

            if (playerWorldBoundingSphere.intersectsBox(obstacleWorldBoundingBox)) {
                hasCollision = true;
            }
        }
    }


    std::shared_ptr<threepp::Mesh> mesh() {
        return _mesh;
    }


private:
    const float maxSize = 7.5f;
    const float minSize = 3.0f;
    std::shared_ptr<threepp::Mesh> _mesh;


};


#endif //EKSAMENOOP_OBSTACLE_HPP



