cmake_minimum_required(VERSION 3.15)
project(CrossyRoad)

set(CMAKE_CXX_STANDARD 17)
find_package(threepp CONFIG REQUIRED)
find_package(imgui CONFIG)

find_package(imgui CONFIG REQUIRED)


add_executable(CrossyRoad app/main.cpp)
target_link_libraries(CrossyRoad PRIVATE threepp::threepp imgui::imgui)
target_link_libraries(CrossyRoad PUBLIC headerLib)
target_include_directories(CrossyRoad PUBLIC "${CMAKE_SOURCE_DIR}/include")
target_include_directories(CrossyRoad PUBLIC "${CMAKE_SOURCE_DIR}/app")


include(FetchContent)
FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v2.13.8
)
FetchContent_MakeAvailable(Catch2)

enable_testing()
add_subdirectory(tests)
add_subdirectory(src)






