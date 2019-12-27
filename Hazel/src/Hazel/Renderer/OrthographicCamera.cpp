#include "OrthographicCamera.h"

#include "glm/gtc/matrix_transform.hpp"

namespace Hazel
{
    OrthographicCamera::OrthographicCamera(const Viewport &viewport)
        : projectionMatrix(glm::ortho(
            viewport.Left,
            viewport.Right,
            viewport.Bottom,
            viewport.Top))
    {
        RecalculateViewMatrix();
    }

    void OrthographicCamera::RecalculateViewMatrix()
    {
        viewMatrix = glm::inverse(
            glm::translate(glm::mat4(1.0f), position)
            * glm::rotate(glm::mat4(1.0f), glm::radians(rotation), {0.0f, 0.0f, 1.0f}));
        viewProjectionMatrix = projectionMatrix * viewMatrix;
    }
}