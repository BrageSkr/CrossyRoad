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
            camera->position.y = cameraCloseY;
            camera->position.x = player->position.x - cameraDistanceCloseX;
            camera->position.z = player->position.z;
            if (!hasCameraRotated) {
                camera->rotateX(math::degToRad(50));
                hasCameraRotated = true;
            }

        }

        if (!cameraButtonClicked) {
            camera->position.y = cameraStartY;
            camera->position.x = player->position.x - cameraDistanceFarX;
            camera->position.z = player->position.z;
            if (!hasCameraRotated1) {
                camera->rotateX(math::degToRad(30));
                hasCameraRotated1 = true;
            }
        }
        if (!cameraButtonClicked && hasCameraRotated) {
            camera->rotateX(math::degToRad(-50));
            hasCameraRotated = false;
        }

        if (cameraButtonClicked && hasCameraRotated1) {
            camera->rotateX(math::degToRad(-30));
            hasCameraRotated1 = false;
        }
    }
private:
    std::shared_ptr<threepp::PerspectiveCamera> _camera;
    const int cameraStartY = 15;
    const int cameraCloseY = 2;
    const int cameraDistanceFarX = 5;
    const int cameraDistanceCloseX = 3;
};

#endif //EKSAMENOOP_CAMERA_HPP
