#include "OrthographicCameraController.h"

namespace Hazel
{
	OrthographicCameraController::OrthographicCameraController(Context &context)
		: input(context.Input),
		aspectRatio(context.Window.GetSize().GetAspectRatio()),
		camera(Rectangle::FromAspectRatio(aspectRatio, zoomLevel))
	{
	}

	void OrthographicCameraController::OnUpdate(float deltaTime)
	{
		UpdateCameraPosition(deltaTime);
		if (rotationEnabled)
		{
			UpdateCameraRotation(deltaTime);
		}
	}

	void OrthographicCameraController::OnWindowResized(WindowResizeEvent &e)
	{
		aspectRatio = e.GetSize().GetAspectRatio();
		UpdateCameraViewport();
	}

	void OrthographicCameraController::OnMouseScrolled(MouseScrollEvent &e)
	{
		zoomLevel = std::max(zoomLevel - 0.2f * e.GetYOffset(), 0.1f);
		UpdateCameraViewport();
	}

	void OrthographicCameraController::UpdateCameraPosition(float deltaTime)
	{
		auto cameraPosition = camera.GetPosition();
		if (input.IsKeyPressed(Key::W))
		{
			cameraPosition.y += translationSpeed * deltaTime;
		}
		if (input.IsKeyPressed(Key::S))
		{
			cameraPosition.y -= translationSpeed * deltaTime;
		}
		if (input.IsKeyPressed(Key::D))
		{
			cameraPosition.x += translationSpeed * deltaTime;
		}
		if (input.IsKeyPressed(Key::A))
		{
			cameraPosition.x -= translationSpeed * deltaTime;
		}
		camera.SetPosition(cameraPosition);
	}

	void OrthographicCameraController::UpdateCameraRotation(float deltaTime)
	{
		auto cameraRotation = camera.GetRotation();
		if (input.IsKeyPressed(Key::Q))
		{
			cameraRotation += rotationSpeed * deltaTime;
		}
		if (input.IsKeyPressed(Key::E))
		{
			cameraRotation -= rotationSpeed * deltaTime;
		}
		camera.SetRotation(cameraRotation);
	}

	void OrthographicCameraController::UpdateCameraViewport()
	{
		camera.SetViewport(Rectangle::FromAspectRatio(aspectRatio, zoomLevel));
	}
}