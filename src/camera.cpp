#include "camera.hpp"

std::shared_ptr<threepp::PerspectiveCamera> myCamera::camera(threepp::Canvas &canvas) {
    auto _camera = PerspectiveCamera::create();
    _camera->rotateZ(math::degToRad(270));
    _camera->rotateY(math::degToRad(-90));

    return _camera;
}

void myCamera::updateCamera(std::shared_ptr<threepp::PerspectiveCamera> camera, bool &cameraButtonClicked,
                            std::shared_ptr<threepp::Mesh> player) {
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
void myCamera::onWindowResize(threepp::WindowSize size, std::shared_ptr<threepp::PerspectiveCamera> camera,
                              threepp::GLRenderer &renderer, threepp::TextHandle &textHandle) {
    camera->aspect = size.getAspect();
    camera->updateProjectionMatrix();
    renderer.setSize(size);
    textHandle.setPosition(0, size.height - 30);
}