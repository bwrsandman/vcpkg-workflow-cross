cmake_minimum_required(VERSION 3.20 FATAL_ERROR)

project(vcpkg-workflow-cross)

add_executable(vcpkg-workflow-cross main.cpp)

enable_testing()
add_test(NAME test COMMAND vcpkg-workflow-cross)
