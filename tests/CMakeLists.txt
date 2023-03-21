add_executable(test_sphere test_sphere.cpp test_sphere.cpp)
add_test(NAME test_sphere COMMAND test_sphere)
target_link_libraries(test_sphere PUBLIC Catch2::Catch2)
target_include_directories(test_sphere PUBLIC "${CMAKE_SOURCE_DIR}/include")
target_include_directories(test_sphere PUBLIC "${CMAKE_SOURCE_DIR}/src")

