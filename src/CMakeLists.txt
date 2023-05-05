set(sources
        gameLogic.cpp
        camera.cpp
        obstacle.cpp sphere.cpp)
add_library(headerLib ${sources})
target_include_directories(headerLib PUBLIC "${CMAKE_SOURCE_DIR}/include")
target_link_libraries(headerLib PUBLIC threepp::threepp imgui::imgui)