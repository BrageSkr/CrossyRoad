
#include "threepp/threepp.hpp"
#include "threepp/extras/imgui/imgui_context.hpp"
#include "obstacle.hpp"
using namespace threepp;

int main() {
    obstacle test;
    Canvas canvas;
    GLRenderer renderer(canvas);
    renderer.setClearColor(Color::aliceblue);

    auto camera = PerspectiveCamera::create();
    camera->position.z = 5;

    OrbitControls controls{camera, canvas};

    auto scene = Scene::create();

    auto group = Group::create();
    scene->add(group);
    group->add(test.create_geometry(1,1,3,1));
    group->add(test.create_geometry(1,1,3,-1));


    renderer.enableTextRendering();
    auto& textHandle = renderer.textHandle("Hello World");
    textHandle.setPosition(0, canvas.getSize().height-30);
    textHandle.scale = 2;


    std::array<float, 3> posBuf{};
    imgui_functional_context ui(canvas.window_ptr(), [&] {
        ImGui::SetNextWindowPos({0, 0}, 0, {0, 0});
        ImGui::SetNextWindowSize({230, 0}, 0);
        ImGui::Begin("Demo");
        ImGui::SliderFloat3("position", posBuf.data(), -1.f, 1.f);
        controls.enabled = !ImGui::IsWindowHovered();
        ImGui::End();
    });

    canvas.onWindowResize([&](WindowSize size){
        camera->aspect = size.getAspect();
        camera->updateProjectionMatrix();
        renderer.setSize(size);
        textHandle.setPosition(0, size.height-30);
    });

    canvas.animate([&] {

        renderer.render(scene, camera);

        ui.render();
        group->position.fromArray(posBuf);

    });

}