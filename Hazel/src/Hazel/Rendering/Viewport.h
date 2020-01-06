#pragma once

#include "glm/glm.hpp"

namespace Hazel
{
    struct Viewport
    {
        float Left = -1.0f;
        float Right = 1.0f;
        float Bottom = -1.0f;
        float Top = 1.0f;

        static inline Viewport FromAspectRatio(float aspectRatio, float zoomLevel = 1.0f)
        {
            return {
                -aspectRatio * zoomLevel,
                aspectRatio * zoomLevel,
                -zoomLevel,
                zoomLevel
            };
        }

        inline glm::mat4 ToProjectionMatrix() const
        {
            return glm::ortho(Left, Right, Bottom, Top);
        }
    };
}