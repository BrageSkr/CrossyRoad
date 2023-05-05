#include "sphere.hpp"

sphere::sphere(float position_x) {
    auto geometry = threepp::SphereGeometry::create(0.4f, 20, 20);
    meshBasicMaterial = threepp::MeshBasicMaterial::create();
    meshBasicMaterial->color = 0xFF0000;
    _mesh = threepp::Mesh::create(geometry, meshBasicMaterial);
    _mesh->position.x = position_x;
    _mesh->name = "sphere";
    _mesh->geometry()->computeBoundingSphere();
}

std::shared_ptr<threepp::Mesh> sphere::mesh() {
    return _mesh;  //returns the _mesh as a shared pointer
}

void sphere::update(float dt, const keyInput &input, int hexColor, bool hasCollision) {
    if (input.up) {
        move_forwards(dt);
    } else if (input.down) {
        move_backwards(dt);
    } else if (input.right) {
        move_right(dt);
    } else if (input.left) {
        move_left(dt);
    } else if (input.reset) {
        reset();
    }
    if (hasCollision) {
        reset();
    }
    updateColor(hexColor);
}

void sphere::move_forwards(float dt) {
    _mesh->position.x += speed * dt;
}

void sphere::move_backwards(float dt) {
    _mesh->position.x += -speed * dt;
}

void sphere::move_right(float dt) {
    _mesh->position.z += speed * dt;
}

void sphere::move_left(float dt) {
    _mesh->position.z += -speed * dt;
}

void sphere::reset() {
    _mesh->position.x = 0;
    _mesh->position.z = 0;
}

void sphere::changeColor() {
    meshBasicMaterial->color = newColor;
}

void sphere::updateColor(int hexColor) {
    newColor = hexColor;
    changeColor();
}


