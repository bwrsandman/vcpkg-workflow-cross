cmake_minimum_required(VERSION 3.20 FATAL_ERROR)

project(vcpkg-workflow-cross)

add_executable(vcpkg-workflow-cross main.cpp)

find_package(spdlog CONFIG REQUIRED)
find_package(Bullet CONFIG REQUIRED)
find_package(cxxopts CONFIG REQUIRED)
find_package(EnTT CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(GTest CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)
find_package(unofficial-minizip CONFIG REQUIRED)
find_package(SDL2 CONFIG REQUIRED)
find_package(Stb REQUIRED)

target_link_libraries(vcpkg-workflow-cross PRIVATE
    ${BULLET_LIBRARIES}
    spdlog::spdlog
    SDL2::SDL2
    cxxopts::cxxopts
    EnTT::EnTT
    glm::glm
    GTest::gmock GTest::gmock_main
    imgui::imgui
    unofficial::minizip::minizip
)
target_include_directories(vcpkg-workflow-cross PRIVATE ${Stb_INCLUDE_DIR})

enable_testing()
add_test(NAME test COMMAND vcpkg-workflow-cross)
