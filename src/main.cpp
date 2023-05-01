
#include <sstream>
#include "threepp/threepp.hpp"
#include "threepp/extras/imgui/imgui_context.hpp"
#include "obstacle.hpp"
#include "sphere.hpp"

using namespace threepp;
const float toRadians = 3.14159265358979323846264 / 180;

unsigned int updateHexColor(ImColor color) {
    unsigned int hexColor = ((unsigned int) (color.Value.x * 255.0f) << 16) |
                            ((unsigned int) (color.Value.y * 255.0f) << 8) |
                            ((unsigned int) (color.Value.z * 255.0f));
    return hexColor;
}


int main() {
    sphere player(0);
    auto grid = GridHelper::create(100, 100, Color::green, Color::pink);
    Canvas canvas;
    GLRenderer renderer(canvas);
    renderer.setClearColor(Color::whitesmoke);
    auto camera = PerspectiveCamera::create();
    camera->rotateZ(270 * toRadians);
    camera->rotateY(-90*toRadians);
   // camera->position.x = player.mesh()->position.x + 5;
    auto scene = Scene::create();
    auto group = Group::create();
    scene->add(player.mesh());
    scene->add(group);
    scene->add(grid);
    obstacle obstacles;
    obstacles.createObstalces(group);

    renderer.enableTextRendering();
    auto &textHandle = renderer.textHandle();
    textHandle.setPosition(0, canvas.getSize().height - 30);
    textHandle.scale = 2;

    ImColor color(0.9411765f, 0.972549f, 1.0f, 1.0f);
    bool buttonClicked = false;
    imgui_functional_context ui(canvas.window_ptr(), [&] {
        ImGui::SetNextWindowPos({0, 0}, 0, {0, 0});
        ImGui::SetNextWindowSize({150, 0}, 0);
        ImGui::Begin("Color Picker");
        ImGui::ColorPicker4("Color", reinterpret_cast<float*>(&color), ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoSidePreview | ImGuiColorEditFlags_NoSmallPreview);
        if (ImGui::Button("Change camera")) {
            buttonClicked = !buttonClicked;
        }
        ImGui::End();
    });

    canvas.onWindowResize([&](WindowSize size) {
        camera->aspect = size.getAspect();
        camera->updateProjectionMatrix();
        renderer.setSize(size);
        textHandle.setPosition(0, size.height - 30);
    });
    myKeyListener keyListner_;
    canvas.addKeyListener(&keyListner_); //adding the keylistner in the class to the canvas
    float distance = 0;
    int score = 0;
    int hightestScore = 0;
    bool hasCameraRotated = false;
    bool hasCameraRotated1 = false;
    canvas.animate([&](float dt) {  //f
        keyInput button = keyListner_.getKeyInput();
        player.update(dt, button);
        auto playerBoundingSphere = player.mesh()->geometry()->boundingSphere; // get bounding box of player
        auto playerWorldBoundingSphere = playerBoundingSphere->clone().applyMatrix4((*player.mesh()->matrixWorld));
        group->position.z += 1.f * dt;
        bool hasCollision = false;

        for (auto &obstacle: group->children) {
            auto obstacleBoundingBox = obstacle->geometry()->boundingBox; // get bounding box of obstacle
            auto obstacleWorldBoundingBox = obstacleBoundingBox->clone().applyMatrix4(*obstacle->matrixWorld);// compute the world-space bounding box of the obstacle

            if (playerWorldBoundingSphere.intersectsBox(obstacleWorldBoundingBox)) {
                hasCollision = true;
            }
        }

        if (hasCollision) {
            player.reset();
        }

        if (group->position.z >= 20) {
            group->position.z = -20;
        }
        unsigned int hexColor = updateHexColor(color);
        distance = player.mesh()->position.x;
        score = distance/2;
        if(score<0){
            score = 0;
        }
        if(score > hightestScore){
            hightestScore = score;
        }
        if (player.mesh()->position.x>60){
            player.mesh()->position.x = 0;
        }
        if (buttonClicked) {
            camera->position.y = 1.f;
            camera->position.x = player.mesh()->position.x - 3;
            camera->position.z = player.mesh()->position.z;
            if (!hasCameraRotated) {
                camera->rotateX(60 * toRadians);
                hasCameraRotated = true;
            }

        }

        if (!buttonClicked) {
            camera->position.y = 15;
            camera->position.x = player.mesh()->position.x - 5;
            camera->position.z = player.mesh()->position.z;
            if (!hasCameraRotated1) {
                camera->rotateX(30 * toRadians);
                hasCameraRotated1 = true;
            }
        }
        if (!buttonClicked && hasCameraRotated) {
            camera->rotateX(-60 * toRadians);
            hasCameraRotated = false;
        }

        if (buttonClicked && hasCameraRotated1) {
            camera->rotateX(-30 * toRadians);
            hasCameraRotated1 = false;
        }


        renderer.render(scene, camera);
        textHandle.setText("Hi-Score: " + std::to_string(hasCameraRotated)+ " Score: " + std::to_string(score));
        renderer.setClearColor(hexColor);
        ui.render();

    });

}



