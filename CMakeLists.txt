cmake_minimum_required(VERSION 3.20 FATAL_ERROR)

project(vcpkg-workflow-cross)

set(CMAKE_FIND_DEBUG_MODE TRUE)
find_package(spdlog CONFIG REQUIRED)
find_package(OpenAL CONFIG REQUIRED)
set(CMAKE_FIND_DEBUG_MODE FALSE)

add_executable(vcpkg-workflow-cross main.cpp)

target_link_libraries(vcpkg-workflow-cross PRIVATE
    spdlog::spdlog
    OpenAL::OpenAL
)
enable_testing()
add_test(NAME test COMMAND vcpkg-workflow-cross)

if (EMSCRIPTEN)
  set_target_properties(vcpkg-workflow-cross PROPERTIES COMPILE_FLAGS "-mbulk-memory -matomics -s USE_PTHREADS=1" SUFFIX ".html")
endif ()
if (VCPKG_TARGET_TRIPLET STREQUAL "x86-linux")
    set(CMAKE_C_FLAGS -m32)
    set(CMAKE_CXX_FLAGS -m32)
endif()
