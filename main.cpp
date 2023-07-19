#include <cstdint>
#include <spdlog/spdlog.h>
#include <AL/al.h>

int main(int argc, char* argv[])
{
    spdlog::info("{}", alGetString(AL_FORMAT_MONO8));
    return 0;
}
