#include "threepp/threepp.hpp"
#include "threepp/extras/imgui/imgui_context.hpp"
#include "obstacle.hpp"
#include "sphere.hpp"
#include "camera.hpp"
#include "gameLogic.hpp"

using namespace threepp;

unsigned int updateHexColor(ImColor color) {
    unsigned int hexColor = ((unsigned int) (color.Value.x * 255.0f) << 16) |
                            ((unsigned int) (color.Value.y * 255.0f) << 8) |
                            ((unsigned int) (color.Value.z * 255.0f));
    return hexColor;
}


int main() {
    sphere player(0);
    Canvas canvas;
    myCamera camera1;
    auto camera = camera1.camera(canvas);
    auto grid = GridHelper::create(100, 100, Color::green, Color::pink);
    GLRenderer renderer(canvas);
    renderer.setClearColor(Color::aliceblue);
    auto player1 = player.mesh();
    auto scene = Scene::create();
    auto group1 = Group::create();
    auto group2 = Group::create();
    scene->add(grid);
    scene->add(player.mesh());
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
    float distance = 0;
    int score = 0;
    int hightestScore = 0;
    bool hasCameraRotated = false;
    bool hasCameraRotated1 = false;
   GameLogic gameLogicInst;
    canvas.animate([&](float dt) {
        keyInput button = keyListner_.getKeyInput();
        unsigned int hexColor = updateHexColor(color);
        auto playerBoundingSphere = player.mesh()->geometry()->boundingSphere; // get bounding box of player
        auto playerWorldBoundingSphere = playerBoundingSphere->clone().applyMatrix4((*player.mesh()->matrixWorld));
        bool hasCollision = false;
         obstacles.updateHitbox(group1,group2,hasCollision,playerWorldBoundingSphere);
         player.update(dt, button, hexColor,hasCollision);
        gameLogicInst.updateGame(player1,group1,group2,dt);

        distance = player.mesh()->position.x;
        score = distance / 2;
        if (score < 0) {
            score = 0;
        }
        if (score > hightestScore) {
            hightestScore = score;
        }
        camera1.updateCamera(camera,cameraButtonClicked,player1,hasCameraRotated1,hasCameraRotated);
        renderer.render(scene, camera);
        textHandle.setText("Hi-Score: " + std::to_string(hightestScore) + " Score: " + std::to_string(score));
        ui.render();
    });

}



