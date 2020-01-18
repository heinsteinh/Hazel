#pragma once

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include "Hazel/Utils/Angle.h"

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
            return {-width / 2.0f, width / 2.0f, -height / 2.0f, height / 2.0f};
        }

        constexpr Rectangle() = default;

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

        constexpr float GetX() const
        {
            return (right + left) / 2.0f;
        }

        constexpr float GetY() const
        {
            return (top + bottom) / 2.0f;
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

        inline glm::mat4 ToProjectionMatrix() const
        {
            return glm::ortho(left, right, bottom, top);
        }

        inline glm::mat4 GetTransform(Angle rotation = 0.0_deg) const
        {
            return glm::scale(
                glm::rotate(
                    glm::translate(
                        glm::mat4(1.0f),
                        {GetX(), GetY(), 0.0f}),
                    rotation.ToRadians(),
                    {0.0f, 0.0f, 1.0f}),
                {GetWidth(), GetHeight(), 1.0f});
        }

        constexpr bool operator==(const Rectangle &other) const = default;
        constexpr bool operator!=(const Rectangle &other) const = default;
    };
}