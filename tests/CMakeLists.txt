add_executable(test_sphere test_sphere.cpp)
add_test(NAME test_sphere COMMAND test_sphere)
target_link_libraries(test_sphere PUBLIC Catch2::Catch2 threepp::threepp)
target_link_libraries(test_sphere PUBLIC headerLib)

add_executable(test_myKeylistner test_myKeylistner.cpp test_myKeylistner.cpp)
add_test(NAME test_myKeylistner COMMAND test_myKeylistner)
target_link_libraries(test_myKeylistner PUBLIC Catch2::Catch2 threepp::threepp)
target_include_directories(test_myKeylistner PUBLIC "${CMAKE_SOURCE_DIR}/include")

add_executable(test_myGameLogic test_myFunctions.cpp)
add_test(NAME test_myGameLogic COMMAND test_myGameLogic)
target_link_libraries(test_myGameLogic PUBLIC Catch2::Catch2 threepp::threepp imgui::imgui)
target_link_libraries(test_myGameLogic PUBLIC headerLib)

add_executable(test_obstacle test_obstacle.cpp)
add_test(NAME test_obstacle COMMAND test_obstacle)
target_link_libraries(test_obstacle PUBLIC Catch2::Catch2 threepp::threepp)
target_link_libraries(test_obstacle PUBLIC headerLib)


