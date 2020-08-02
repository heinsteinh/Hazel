#include "OrthographicCameraController.h"

namespace Hazel
{
	OrthographicCameraController::OrthographicCameraController(const OrthographicCameraControllerInfo &info)
		: input(info.Input),
		settings(info.Settings),
		camera(info.Camera)
	{
	}

	void OrthographicCameraController::OnUpdate(float deltaTime)
	{
		UpdateCameraPosition(deltaTime);
		UpdateCameraRotation(deltaTime);
	}

	void OrthographicCameraController::OnWindowResized(WindowResizeEvent &e)
	{
		camera.SetAspectRatio(e.GetSize().GetAspectRatio());
	}

	void OrthographicCameraController::OnMouseScrolled(MouseScrollEvent &e)
	{
		camera.SetZoomLevel(settings.Bounds.ClampZ(
			camera.GetZoomLevel() + e.GetOffset().y * settings.ZoomSpeed));
	}

	void OrthographicCameraController::UpdateCameraPosition(float deltaTime)
	{
		auto position = camera.GetPosition();
		auto deltaPosition = settings.TranslationSpeed * deltaTime;
		if (input.IsKeyPressed(settings.Up))
		{
			position.y += deltaPosition;
		}
		if (input.IsKeyPressed(settings.Down))
		{
			position.y -= deltaPosition;
		}
		if (input.IsKeyPressed(settings.Right))
		{
			position.x += deltaPosition;
		}
		if (input.IsKeyPressed(settings.Left))
		{
			position.x -= deltaPosition;
		}
		camera.SetPosition(settings.Bounds.Clamp(position));
	}

	void OrthographicCameraController::UpdateCameraRotation(float deltaTime)
	{
		auto rotation = camera.GetRotation();
		auto deltaRotation = settings.RotationSpeed * deltaTime;
		if (input.IsKeyPressed(settings.ClockwiseRotation))
		{
			rotation -= deltaRotation;
		}
		if (input.IsKeyPressed(settings.CounterClockwiseRotation))
		{
			rotation += deltaRotation;
		}
		camera.SetRotation(rotation);
	}
}