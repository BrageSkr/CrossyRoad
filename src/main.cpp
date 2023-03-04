
#include "threepp/threepp.hpp"
#include "threepp/extras/imgui/imgui_context.hpp"
#include "obstacle.hpp"
#include "sphere.hpp"
using namespace threepp;
float randGen(){
    float number = math::randomInRange(0.1f,8.0f);
    return number;
};
int main() {

    obstacle test;
    sphere player;
    auto ball = player.create_geometry(0);
    auto grid = GridHelper::create(100,100,Color:: green, Color::pink);
    Canvas canvas;
    GLRenderer renderer(canvas);
    renderer.setClearColor(Color::aliceblue);

    auto camera = PerspectiveCamera::create();
    camera->position.y =20;

    OrbitControls controls{camera, canvas};

    auto scene = Scene::create();

    auto group = Group::create();
    scene->add(group);
    scene->add(grid);
    group->add(ball);
    for (int i = 0; i < 20; ++i) {
        float width = randGen();
        group->add(test.create_geometry(1,1,width,i*2,5));

    }
    for (int i = 0; i < 20; ++i) {
        float width = randGen();
        group->add(test.create_geometry(1,1,width,i*2,-5));

    }


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