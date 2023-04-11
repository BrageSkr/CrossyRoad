
#include "threepp/threepp.hpp"
#include "threepp/extras/imgui/imgui_context.hpp"
#include "obstacle.hpp"
#include "sphere.hpp"

using namespace threepp;

float randGen() {  //function that generates a random number for the size of obstacles, will be implemented in the class
    float number = math::randomInRange(0.1f, 9.0f);
    return number;
};

int main() {
    sphere player(0);
    auto grid = GridHelper::create(100, 100, Color::green, Color::pink);
    Canvas canvas;
    GLRenderer renderer(canvas);
    renderer.setClearColor(Color::aliceblue);
    auto camera = PerspectiveCamera::create();
    camera->position.y = 50;
    OrbitControls controls{camera, canvas};
    auto scene = Scene::create();
    auto group = Group::create();
    auto group1 = Group::create();
    scene->add(group);
    scene->add(group1);
    scene->add(grid);
    group->add(player.mesh());
    for (int j = -50;
         j <= 50; j += 9) {   //for- loop that creates the obstacles, plan to be implemented in a class at a later time
        for (int i = 0; i < 30; ++i) {
            float width = randGen();
            obstacle test(width, (i * 2) + 2, j);
            group1->add(test.mesh());
        }
    }

    renderer.enableTextRendering();
    auto &textHandle = renderer.textHandle();
    textHandle.setPosition(0, canvas.getSize().height - 30);
    textHandle.scale = 2;


    std::array<float, 3> posBuf{}; //imgui setup for rotating the camera
    imgui_functional_context ui(canvas.window_ptr(), [&] {
        ImGui::SetNextWindowPos({0, 0}, 0, {0, 0});
        ImGui::SetNextWindowSize({230, 0}, 0);
        ImGui::Begin("Demo");
        ImGui::SliderFloat3("position", posBuf.data(), -10.f, 10.f);
        controls.enabled = !ImGui::IsWindowHovered();
        ImGui::End();
    });

    canvas.onWindowResize([&](WindowSize size) {
        camera->aspect = size.getAspect();
        camera->updateProjectionMatrix();
        renderer.setSize(size);
        textHandle.setPosition(0, size.height - 30);
    });
    canvas.addKeyListener(&player); //adding the keylistner in the class to the canvas
    float Time = 0;

    canvas.animate([&](float dt) {  //functions that will be updated with every render, like movement and logic

        player.update(dt);

        std::vector<std::shared_ptr<Object3D>> closestObstacles;

        float closestDistance = std::numeric_limits<float>::max();
        for (auto &obstacle: group1->children) {
            float distance = player.mesh()->position.distanceTo(obstacle->position);
            if (distance < closestDistance) {
                closestDistance = distance;
                closestObstacles = {obstacle};
            } else if (distance == closestDistance) {
                closestObstacles.push_back(obstacle);
            }
        }


        group1->position.z += 2.f * dt;
        Time += 1.f * dt;
        if (group1->position.z >= 20) {
            group1->position.z = -20;
        }
        renderer.render(scene, camera);
        textHandle.setText("Time: " + std::to_string(closestDistance));

        ui.render();

    });

}



