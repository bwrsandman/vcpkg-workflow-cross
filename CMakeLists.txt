cmake_minimum_required(VERSION 3.20 FATAL_ERROR)

project(vcpkg-workflow-cross)

find_package(spdlog CONFIG REQUIRED)
find_package(bgfx CONFIG REQUIRED)

bgfx_compile_binary_to_header(
  INPUT_FILE ${CMAKE_CURRENT_SOURCE_DIR}/binary.bin
  OUTPUT_FILE ${CMAKE_BINARY_DIR}/include/binary.h
  ARRAY_NAME binary_data
)

add_executable(vcpkg-workflow-cross binary.bin main.cpp)

target_link_libraries(vcpkg-workflow-cross PRIVATE
    spdlog::spdlog
    bgfx::bx
)
target_include_directories(vcpkg-workflow-cross PRIVATE ${CMAKE_BINARY_DIR}/include)
enable_testing()
add_test(NAME test COMMAND vcpkg-workflow-cross)

get_property(my_package_include_dirs
             TARGET bgfx::bx
             PROPERTY INTERFACE_INCLUDE_DIRECTORIES)

message("Include directories of MyPackage: ${my_package_include_dirs}")
