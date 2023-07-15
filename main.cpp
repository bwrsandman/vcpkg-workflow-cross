#include <cstdint>
#include <spdlog/spdlog.h>
#include <bx/bx.h>
#include <bgfx/bgfx.h>
#include "binary.h"

int main(int argc, char* argv[])
{
    bgfx::frame();
    spdlog::info("Cpu: {}, Arch: {}, CRT: {}, CPP: {}, Platform: {}", BX_CPU_NAME, BX_ARCH_NAME, BX_CRT_NAME, BX_CPP_NAME, BX_PLATFORM_NAME);
    spdlog::info("binary contents: {}", binary_data[0]);
    return 0;
}
