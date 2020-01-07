#pragma once

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

namespace Hazel
{
    struct Viewport
    {
        float Left = -1.0f;
        float Right = 1.0f;
        float Bottom = -1.0f;
        float Top = 1.0f;

        static constexpr Viewport FromAspectRatio(float aspectRatio, float zoomLevel = 1.0f)
        {
            return {
                -aspectRatio * zoomLevel,
                aspectRatio * zoomLevel,
                -zoomLevel,
                zoomLevel
            };
        }

        static constexpr Viewport FromDimensions(float width, float height)
        {
            return {0.0f, width, 0.0f, height};
        }

        inline glm::mat4 ToProjectionMatrix() const
        {
            return glm::ortho(Left, Right, Bottom, Top);
        }

        constexpr float GetWidth() const
        {
            return Right - Left;
        }

        constexpr float GetHeight() const
        {
            return Top - Bottom;
        }

        constexpr auto GetMiddlePoint() const
        {
            return std::make_pair((Top + Bottom) / 2, (Right - Left) / 2);
        }
    };
}