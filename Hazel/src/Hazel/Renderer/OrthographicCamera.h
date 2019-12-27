#pragma once

#include "glm/glm.hpp"

#include "Hazel/Core/Core.h"

namespace Hazel
{
    class HAZEL_API OrthographicCamera
    {
    public:
        struct Viewport
        {
            float Left = 0.0f;
            float Right = 0.0f;
            float Bottom = 0.0f;
            float Top = 0.0f;
        };

    private:
        glm::vec3 position = {0.0f, 0.0f, 0.0f};
        float rotation = 0.0f;
        glm::mat4 projectionMatrix{1.0f};
        glm::mat4 viewMatrix{1.0f};
        glm::mat4 viewProjectionMatrix{1.0f};

    public:
        OrthographicCamera(const Viewport &viewport = {-1.0f, 1.0f, -1.0f, 1.0f});

        inline const glm::vec3 &GetPosition() const
        {
            return position;
        }

        inline float GetRotation() const
        {
            return rotation;
        }

        inline void SetPosition(const glm::vec3 &position)
        {
            this->position = position;
            RecalculateViewMatrix();
        }

        inline void SetRotation(float rotation)
        {
            this->rotation = rotation;
            RecalculateViewMatrix();
        }

        inline const glm::mat4 &GetProjectionMatrix() const
        {
            return projectionMatrix;
        }

        inline const glm::mat4 &GetViewMatrix() const
        {
            return viewMatrix;
        }

        inline const glm::mat4 &GetViewProjectionMatrix() const
        {
            return viewProjectionMatrix;
        }

    private:
        void RecalculateViewMatrix();
    };
}