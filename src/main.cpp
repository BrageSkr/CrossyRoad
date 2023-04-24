
#include "threepp/threepp.hpp"
#include "threepp/extras/imgui/imgui_context.hpp"
#include "obstacle.hpp"
#include "sphere.hpp"

using namespace threepp;

float randGen() {  //function that generates a random number for the size of obstacles, will be implemented in the class
    float number = math::randomInRange(0.1f, 9.0f);
    return number;
}

int main() {
    sphere player(0);
    auto grid = GridHelper::create(100, 100, Color::green, Color::pink);
    Canvas canvas;
    GLRenderer renderer(canvas);
    renderer.setClearColor(Color::aliceblue);
    auto camera = PerspectiveCamera::create();
    camera->position.y = 20;
    OrbitControls controls{camera, canvas};
    camera->rotateZ(1.57079633 * 3);
    auto scene = Scene::create();
    auto group = Group::create();
    scene->add(player.mesh());
    scene->add(group);
    scene->add(grid);
    for (int j = -50;
         j <= 50; j += 9) {   //for-loop that creates the obstacles, plan to be implemented in a class at a later time
        for (int i = 0; i < 30; ++i) {
            float width = randGen();
            obstacle test(width, (i * 2) + 2, j);
            group->add(test.mesh());
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
    std::string collision = "";
    float distance = 0;
    canvas.animate([&](float dt) {  //functions that will be updated with every render, like movement and logic
        player.update(dt);
        auto playerBoundingSphere = player.mesh()->geometry()->boundingSphere; // get bounding box of player
        auto playerWorldBoundingSphere = playerBoundingSphere->clone().applyMatrix4((*player.mesh()->matrixWorld));
        group->position.z += 1.f * dt;
        bool hasCollision = false;

        for (auto &obstacle: group->children) {
            auto obstacleBoundingBox = obstacle->geometry()->boundingBox; // get bounding box of obstacle
            auto obstacleWorldBoundingBox = obstacleBoundingBox->clone().applyMatrix4(
                    *obstacle->matrixWorld);// compute the world-space bounding box of the obstacle

            if (playerWorldBoundingSphere.intersectsBox(obstacleWorldBoundingBox)) {
                hasCollision = true;

            }
        }
        if (hasCollision) {
            collision = "true";
            player.reset();
        } else {
            collision = "false";
        }

        if (group->position.z >= 20) {
            group->position.z = -20;
        }
        distance = player.mesh()->position.x;
        renderer.render(scene, camera);
        textHandle.setText("Distance: " + std::to_string(distance));
        camera->position.x = player.mesh()->position.x;
        camera->position.z = player.mesh()->position.z;
        ui.render();

    });

}



