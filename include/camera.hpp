#ifndef EKSAMENOOP_CAMERA_HPP
#define EKSAMENOOP_CAMERA_HPP

#include "threepp/threepp.hpp"

using namespace threepp;

class myCamera {
public:
    std::shared_ptr<threepp::PerspectiveCamera> camera(threepp::Canvas &canvas);

    void updateCamera(std::shared_ptr<threepp::PerspectiveCamera> camera, bool &cameraButtonClicked,
                      std::shared_ptr<threepp::Mesh> player, bool &hasCameraRotated, bool &hasCameraRotated1);

private:
    std::shared_ptr<threepp::PerspectiveCamera> _camera;
    const int cameraStartY = 15;
    const int cameraCloseY = 2;
    const int cameraDistanceFarX = 5;
    const int cameraDistanceCloseX = 3;
};

#endif //EKSAMENOOP_CAMERA_HPP
