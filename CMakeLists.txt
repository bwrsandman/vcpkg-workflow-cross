cmake_minimum_required(VERSION 3.20 FATAL_ERROR)

project(vcpkg-workflow-cross)

add_executable(vcpkg-workflow-cross main.cpp)

find_package(spdlog CONFIG REQUIRED)
find_package(bgfx CONFIG REQUIRED)

target_link_libraries(vcpkg-workflow-cross PRIVATE
    spdlog::spdlog
    bgfx::bx
)
enable_testing()
add_test(NAME test COMMAND vcpkg-workflow-cross)

get_property(my_package_include_dirs
             TARGET bgfx::bx
             PROPERTY INTERFACE_INCLUDE_DIRECTORIES)

message("Include directories of MyPackage: ${my_package_include_dirs}")
