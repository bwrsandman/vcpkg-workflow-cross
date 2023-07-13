#include <spdlog/spdlog.h>

int main(int argc, char* argv[])
{
    #if defined(__i386__) || defined(_M_IX86)
    spdlog::info("Architecture: x86 (32-bit)");
    #elif defined(__x86_64__) || defined(_M_X64)
    spdlog::info("Architecture: x64 (64-bit)");
    #elif defined(__arm__)
    spdlog::info("Architecture: ARM (32-bit)");
    #elif defined(__aarch64__)
    spdlog::info("Architecture: ARM (64-bit)");
    #else
    spdlog::info("Architecture: Unknown");
    #endif
    return 1;
}
