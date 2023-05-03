#ifndef EKSAMENOOP_CAMERA_HPP
#define EKSAMENOOP_CAMERA_HPP

#include "threepp/threepp.hpp"

using namespace threepp;

class myCamera {
public:
    auto camera(Canvas &canvas) {
        auto _camera = PerspectiveCamera::create();
        _camera->rotateZ(math::degToRad(270));
        _camera->rotateY(math::degToRad(-90));

        return _camera;
    }

    void updateCamera(std::shared_ptr<threepp::PerspectiveCamera> camera, bool &cameraButtonClicked,
                      std::shared_ptr<threepp::Mesh> player, bool &hasCameraRotated, bool &hasCameraRotated1) {
        if (cameraButtonClicked) {
            camera->position.y = 1.f;
            camera->position.x = player->position.x - 3;
            camera->position.z = player->position.z;
            if (!hasCameraRotated) {
                camera->rotateX(math::degToRad(60));
                hasCameraRotated = true;
            }

        }

        if (!cameraButtonClicked) {
            camera->position.y = 15;
            camera->position.x = player->position.x - 5;
            camera->position.z = player->position.z;
            if (!hasCameraRotated1) {
                camera->rotateX(math::degToRad(30));
                hasCameraRotated1 = true;
            }
        }
        if (!cameraButtonClicked && hasCameraRotated) {
            camera->rotateX(math::degToRad(-60));
            hasCameraRotated = false;
        }

        if (cameraButtonClicked && hasCameraRotated1) {
            camera->rotateX(math::degToRad(-30));
            hasCameraRotated1 = false;
        }
    }
private:
    std::shared_ptr<threepp::PerspectiveCamera> _camera;
};

#endif //EKSAMENOOP_CAMERA_HPP
