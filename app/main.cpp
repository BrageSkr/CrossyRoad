#include "threepp/threepp.hpp"
#include "threepp/extras/imgui/imgui_context.hpp"
#include "obstacle.hpp"
#include "sphere.hpp"
#include "camera.hpp"
#include "gameLogic.hpp"
#include "functions.hpp"

using namespace threepp;

int main() {
    sphere player(0);
    Canvas canvas;
    myCamera camera1;
    auto camera = camera1.camera(canvas);
    auto grid = GridHelper::create(1000, 1000, Color::green, Color::pink);
    GLRenderer renderer(canvas);
    renderer.setClearColor(Color::aliceblue);
    auto player1 = player.mesh();
    auto scene = Scene::create();
    auto group1 = Group::create();
    auto group2 = Group::create();
    scene->add(grid);
    scene->add(player1);
    obstacle obstacles;
    obstacles.createObstacles(group1, group2);
    scene->add(group1);
    scene->add(group2);
    renderer.enableTextRendering();
    auto &textHandle = renderer.textHandle();
    textHandle.setPosition(0, canvas.getSize().height - 30);
    textHandle.scale = 2;

    ImColor color(1.0, 0.0f, 0.0f, 1.0f);
    bool cameraButtonClicked = false;
    imgui_functional_context ui(canvas.window_ptr(), [&] {
        ImGui::SetNextWindowPos({0, 0}, 0, {0, 0});
        ImGui::SetNextWindowSize({150, 0}, 0);
        ImGui::Begin("Color Picker");
        ImGui::ColorPicker4("Color", reinterpret_cast<float *>(&color),
                            ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel |
                            ImGuiColorEditFlags_NoSidePreview | ImGuiColorEditFlags_NoSmallPreview);
        if (ImGui::Button("Change camera")) {
            cameraButtonClicked = !cameraButtonClicked;
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

    GameLogic gameLogicInst;
    canvas.animate([&](float dt) {

        keyInput button = keyListner_.getKeyInput();
        unsigned int hexColor = updateHexColor(color);
        bool hasCollision = false;

        obstacles.updateHitbox(group1, group2, hasCollision, player1);
        player.update(dt, button, hexColor, hasCollision);
        gameLogicInst.updateGame(player1, group1, group2, dt, textHandle,hasCollision);

        camera1.updateCamera(camera, cameraButtonClicked, player1);
        renderer.render(scene, camera);

        ui.render();
    });

}


