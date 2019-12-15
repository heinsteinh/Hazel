#pragma once

namespace Hazel
{
    class Renderer
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