cmake_minimum_required(VERSION 3.15)
project(EksamenOOP)

set(CMAKE_CXX_STANDARD 17)
find_package(threepp CONFIG REQUIRED)
find_package(imgui CONFIG)

find_package(imgui CONFIG REQUIRED)


add_executable(eksamenOOP app/main.cpp include/obstacle.hpp include/sphere.hpp include/myKeylistener.hpp include/camera.hpp include/gameLogic.hpp)
target_link_libraries(eksamenOOP PRIVATE threepp::threepp imgui::imgui)
target_include_directories(eksamenOOP PUBLIC "${CMAKE_SOURCE_DIR}/include")
target_include_directories(eksamenOOP PUBLIC "${CMAKE_SOURCE_DIR}/app")


include(FetchContent)
FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v2.13.8
)
FetchContent_MakeAvailable(Catch2)

enable_testing()
add_subdirectory(tests)





