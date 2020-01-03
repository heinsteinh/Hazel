#include "Platform.h"

#include "Platform/Windows/WindowsPlatform.h"

namespace Hazel
{
    Platform &Platform::Get()
    {
#ifdef _WIN64
        static WindowsPlatform platform;
#else
#error Platform not implemented
#endif
        return platform;
    }
}