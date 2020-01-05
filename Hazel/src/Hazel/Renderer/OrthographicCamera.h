#pragma once

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include "Viewport.h"

namespace Hazel
{
    class HAZEL_API OrthographicCamera
    {
    private:
        glm::vec3 position = {0.0f, 0.0f, 0.0f};
        Angle rotation;
        glm::mat4 projectionMatrix{1.0f};
        glm::mat4 viewMatrix{1.0f};
        glm::mat4 viewProjectionMatrix{1.0f};

    public:
        OrthographicCamera(const Viewport &viewport = {})
            : projectionMatrix(viewport.ToProjectionMatrix())
        {
            RecalculateViewProjectionMatrix();
        }

        inline const glm::vec3 &GetPosition() const
        {
            return position;
        }

        inline Angle GetRotation() const
        {
            return rotation;
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

        inline void SetViewport(const Viewport &viewport)
        {
            projectionMatrix = viewport.ToProjectionMatrix();
            RecalculateViewProjectionMatrix();
        }

        inline void SetPosition(const glm::vec3 &position)
        {
            this->position = position;
            RecalculateViewMatrix();
        }

        inline void SetRotation(Angle rotation)
        {
            this->rotation = rotation;
            RecalculateViewMatrix();
        }

    private:
        inline void RecalculateViewMatrix()
        {
            viewMatrix = glm::translate(
                glm::rotate(
                    glm::mat4(1.0f),
                    -rotation.ToRadians(),
                    {0.0f, 0.0f, 1.0f}),
                -position);
            RecalculateViewProjectionMatrix();
        }

        inline void RecalculateViewProjectionMatrix()
        {
            viewProjectionMatrix = projectionMatrix * viewMatrix;
        }
    };
}