#include "obstacle.hpp"

void obstacle::obstacleGeometry(float w, float p, float pz) {
    auto geometry = BoxGeometry::create(1, 1, w);
    auto material = MeshBasicMaterial::create();
    material->color.randomize();
    _mesh = Mesh::create(geometry, material);
    _mesh->position.x = p;
    _mesh->position.z = pz;
    _mesh->name = "obstacle";
    _mesh->geometry()->computeBoundingBox();
}

void obstacle::createObstacles(std::shared_ptr<threepp::Group> group1, std::shared_ptr<threepp::Group> group2) {
    for (int j = 0; j < rowZ; ++j) {
        for (int i = -rowX; i < rowX; i += distanceBetweenX) {
            float width = math::randomInRange(minSize, maxSize);
            obstacle test;
            test.obstacleGeometry(width, (j * distanceBetweenZ) + 2, i);
            if (j % 2 == 0) {
                group2->add(test.mesh());
            } else {
                group1->add(test.mesh());
            }
        }
    }
}

void obstacle::updateHitbox(std::shared_ptr<threepp::Group> group1, std::shared_ptr<threepp::Group> group2,
                            bool &hasCollision, std::shared_ptr<threepp::Mesh> player) {
    auto playerBoundingSphere = player->geometry()->boundingSphere; // get bounding box of player
    auto playerWorldBoundingSphere = playerBoundingSphere->clone().applyMatrix4((*player->matrixWorld));
    for (auto &obstacle: group1->children) {
        auto obstacleBoundingBox = obstacle->geometry()->boundingBox;
        auto obstacleWorldBoundingBox = obstacleBoundingBox->clone().applyMatrix4(*obstacle->matrixWorld);

        if (playerWorldBoundingSphere.intersectsBox(obstacleWorldBoundingBox)) {
            hasCollision = true;
        }
    }
    for (auto &obstacle: group2->children) {
        auto obstacleBoundingBox = obstacle->geometry()->boundingBox;
        auto obstacleWorldBoundingBox = obstacleBoundingBox->clone().applyMatrix4(*obstacle->matrixWorld);

        if (playerWorldBoundingSphere.intersectsBox(obstacleWorldBoundingBox)) {
            hasCollision = true;
        }
    }
}

std::shared_ptr<threepp::Mesh> obstacle::mesh() {
    return _mesh;
}
