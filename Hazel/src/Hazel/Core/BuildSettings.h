#pragma once

#ifdef _WIN64

#ifdef HZ_BUILD_DYNAMIC

#ifdef HZ_BUILD_DLL
#define HAZEL_API __declspec(dllexport)
#else
#define HAZEL_API __declspec(dllimport)
#endif

#else
#define HAZEL_API
#endif

#else
#error Hazel only supports Windows x64 !
#endif