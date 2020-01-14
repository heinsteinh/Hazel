#pragma once

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

namespace Hazel
{
    class Rectangle
    {
    private:
        float left = 0.0f;
        float right = 0.0f;
        float bottom = 0.0f;
        float top = 0.0f;

    public:
        static constexpr Rectangle FromAspectRatio(float aspectRatio, float zoomLevel = 1.0f)
        {
            return {
                -aspectRatio * zoomLevel,
                aspectRatio * zoomLevel,
                -zoomLevel,
                zoomLevel
            };
        }

        static constexpr Rectangle FromSize(float width, float height)
        {
            return {0.0f, width, 0.0f, height};
        }

        constexpr Rectangle()
        {
        }

        constexpr Rectangle(float left, float right, float bottom, float top)
            : left(left),
            right(right),
            bottom(bottom),
            top(top)
        {
        }

        constexpr float GetLeft() const
        {
            return left;
        }

        constexpr float GetRight() const
        {
            return right;
        }

        constexpr float GetBottom() const
        {
            return bottom;
        }

        constexpr float GetTop() const
        {
            return top;
        }

        inline glm::mat4 ToProjectionMatrix() const
        {
            return glm::ortho(left, right, bottom, top);
        }

        constexpr float GetWidth() const
        {
            return right - left;
        }

        constexpr float GetHeight() const
        {
            return top - bottom;
        }

        constexpr float GetArea() const
        {
            return GetWidth() * GetHeight();
        }

        constexpr bool IsEmpty() const
        {
            return GetWidth() == 0 || GetHeight() == 0;
        }

        constexpr float GetAspectRatio() const
        {
            auto height = GetHeight();
            return height ? GetWidth() / height : 0.0f;
        }

        constexpr glm::vec2 GetMiddle() const
        {
            return {(top + bottom) / 2.0f, (right - left) / 2.0f};
        }

        constexpr bool operator==(const Rectangle &other) const = default;
        constexpr bool operator!=(const Rectangle &other) const = default;
    };
}