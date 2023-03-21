cmake_minimum_required(VERSION 3.15)
project(EksamenOOP)

set(CMAKE_CXX_STANDARD 17)
find_package(threepp CONFIG REQUIRED)
find_package(imgui CONFIG)

if (imgui_FOUND)

    if(EXISTS "${CMAKE_BINARY_DIR}/_deps/imgui_glfw")
        set(imgui_bindings "${CMAKE_BINARY_DIR}/_deps/imgui_glfw")
        add_library(imgui_glfw "${imgui_bindings}/imgui_impl_glfw.cpp" "${imgui_bindings}/imgui_impl_opengl3.cpp" include/obstacle.hpp)
        target_link_libraries(imgui_glfw PUBLIC glad::glad glfw::glfw imgui::imgui)
        target_include_directories(imgui_glfw PUBLIC "${imgui_bindings}")

        set_property(TARGET imgui::imgui APPEND PROPERTY INTERFACE_LINK_LIBRARIES imgui_glfw)
    endif()

    set_property(TARGET imgui::imgui APPEND PROPERTY INTERFACE_COMPILE_DEFINITIONS HAS_IMGUI)

endif ()
add_executable(eksamenOOP src/main.cpp include/obstacle.hpp include/sphere.hpp)
target_link_libraries(eksamenOOP PRIVATE threepp::threepp imgui::imgui)
target_include_directories(eksamenOOP PUBLIC "${CMAKE_SOURCE_DIR}/include")
target_include_directories(eksamenOOP PUBLIC "${CMAKE_SOURCE_DIR}/src")


include(FetchContent)
FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v2.13.8
)
FetchContent_MakeAvailable(Catch2)

enable_testing()
add_subdirectory(tests)





