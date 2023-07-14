#include <spdlog/spdlog.h>
#include <bx/bx.h>

int main(int argc, char* argv[])
{
    spdlog::info("Cpu: {}, Arch: {}, CRT: {}, CPP: {}, Platform: {}", BX_CPU_NAME, BX_ARCH_NAME, BX_CRT_NAME, BX_CPP_NAME, BX_PLATFORM_NAME);
    return 1;
}
