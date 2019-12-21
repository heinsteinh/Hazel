#pragma once

#include "Hazel/Core/Core.h"

namespace Hazel
{
    class HAZEL_API Renderer
    {
    public:
        enum class Api
        {
            None,
            OpenGL
        };

    private:
        static Api api;

    public:
        static inline Api GetApi()
        {
            return api;
        }
    };
}