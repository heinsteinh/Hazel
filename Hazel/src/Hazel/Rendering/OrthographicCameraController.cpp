#include "OrthographicCameraController.h"

namespace Hazel
{
    OrthographicCameraController::OrthographicCameraController(const Window &window)
        : window(window),
        aspectRatio(window.GetAspectRatio()),
        camera(Viewport::FromAspectRatio(aspectRatio, zoomLevel))
    {
    }

    void OrthographicCameraController::OnUpdate(Timestep deltaTime)
    {
        UpdateCameraPosition(deltaTime);
        if (rotationEnabled)
        {
            UpdateCameraRotation(deltaTime);
        }
    }

    void OrthographicCameraController::OnWindowResized(WindowResizedEvent &e)
    {
        aspectRatio = window.GetAspectRatio();
        UpdateCameraViewport();
    }

    void OrthographicCameraController::OnMouseScrolled(MouseScrolledEvent &e)
    {
        zoomLevel -= e.GetYOffset() * 0.2f;
        zoomLevel = std::max(zoomLevel, 0.1f);
        UpdateCameraViewport();
    }

    void OrthographicCameraController::UpdateCameraPosition(Timestep deltaTime)
    {
        auto &input = window.GetInput();
        auto cameraPosition = camera.GetPosition();
        if (input.IsKeyPressed(Key::W))
        {
            cameraPosition.y += translationSpeed * deltaTime.ToSeconds();
        }
        if (input.IsKeyPressed(Key::S))
        {
            cameraPosition.y -= translationSpeed * deltaTime.ToSeconds();
        }
        if (input.IsKeyPressed(Key::D))
        {
            cameraPosition.x += translationSpeed * deltaTime.ToSeconds();
        }
        if (input.IsKeyPressed(Key::A))
        {
            cameraPosition.x -= translationSpeed * deltaTime.ToSeconds();
        }
        camera.SetPosition(cameraPosition);
    }

    void OrthographicCameraController::UpdateCameraRotation(Timestep deltaTime)
    {
        auto &input = window.GetInput();
        auto cameraRotation = camera.GetRotation();
        if (input.IsKeyPressed(Key::Q))
        {
            cameraRotation += rotationSpeed * deltaTime.ToSeconds();
        }
        if (input.IsKeyPressed(Key::E))
        {
            cameraRotation -= rotationSpeed * deltaTime.ToSeconds();
        }
        camera.SetRotation(cameraRotation);
    }

    void OrthographicCameraController::UpdateCameraViewport()
    {
        camera.SetViewport(Viewport::FromAspectRatio(aspectRatio, zoomLevel));
    }
}