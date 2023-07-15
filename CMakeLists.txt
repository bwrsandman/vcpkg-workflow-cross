cmake_minimum_required(VERSION 3.20 FATAL_ERROR)

project(vcpkg-workflow-cross)

find_package(spdlog CONFIG REQUIRED)
find_package(bgfx CONFIG REQUIRED)

bgfx_compile_binary_to_header(
  INPUT_FILE ${CMAKE_CURRENT_SOURCE_DIR}/binary.bin
  OUTPUT_FILE ${CMAKE_BINARY_DIR}/include/binary.h
  ARRAY_NAME binary_data
)

add_executable(vcpkg-workflow-cross main.cpp)

target_link_libraries(vcpkg-workflow-cross PRIVATE
    spdlog::spdlog
    bgfx::bx bgfx::bimg bgfx::bgfx
)
target_include_directories(vcpkg-workflow-cross PRIVATE ${CMAKE_BINARY_DIR}/include)
enable_testing()
add_test(NAME test COMMAND vcpkg-workflow-cross)

# Map CMAKE_HOST_SYSTEM_PROCESSOR value
if(${CMAKE_HOST_SYSTEM_PROCESSOR} STREQUAL "AMD64" OR ${CMAKE_HOST_SYSTEM_PROCESSOR} STREQUAL "x86_64")
    set(OPENBLACK_HOST_ARCH "x64")
elseif(${CMAKE_HOST_SYSTEM_PROCESSOR} STREQUAL "x86" OR ${CMAKE_HOST_SYSTEM_PROCESSOR} STREQUAL "i386")
    set(OPENBLACK_HOST_ARCH "Win32")
elseif(${CMAKE_HOST_SYSTEM_PROCESSOR} STREQUAL "ARM64")
    set(OPENBLACK_HOST_ARCH "ARM64")
else()
    set(OPENBLACK_HOST_ARCH ${CMAKE_HOST_SYSTEM_PROCESSOR})
endif()

set(OPENBLACK_CROSSCOMPILING ${CMAKE_CROSSCOMPILING})
if(MSVC)
    message("msvc")
    if(NOT "${OPENBLACK_HOST_ARCH}" STREQUAL "${CMAKE_VS_PLATFORM_NAME_DEFAULT}")
        message("cross compiling")
    else()
      message("not cross compiling")
    endif()
endif()

message("cross: ${CMAKE_CROSSCOMPILING}")
message("host: ${CMAKE_HOST_SYSTEM_PROCESSOR}")
message("target: ${CMAKE_SYSTEM_PROCESSOR}")
message("vs platform: ${CMAKE_VS_PLATFORM_NAME}")
message("OPENBLACK_HOST_ARCH: ${OPENBLACK_HOST_ARCH}")
