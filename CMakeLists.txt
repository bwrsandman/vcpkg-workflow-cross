cmake_minimum_required(VERSION 3.20 FATAL_ERROR)

project(vcpkg-workflow-cross)

add_executable(vcpkg-workflow-cross main.cpp)

find_package(spdlog CONFIG REQUIRED)
target_link_libraries(vcpkg-workflow-cross PRIVATE spdlog::spdlog)

enable_testing()
add_test(NAME test COMMAND vcpkg-workflow-cross)
