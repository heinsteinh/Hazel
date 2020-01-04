#include "Platform.h"

#include "Platform/Windows/WindowsPlatform.h"

namespace Hazel
{
#ifdef _WIN64
    static WindowsPlatform platform;
#else
#error Platform not implemented
#endif

    Platform &Platform::Get()
    {
        return platform;
    }
}