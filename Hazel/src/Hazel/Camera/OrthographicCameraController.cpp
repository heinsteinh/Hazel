#include "OrthographicCameraController.h"

#include "Hazel/Events/WindowResizeEvent.h"
#include "Hazel/Events/MouseScrollEvent.h"

namespace Hazel
{
	OrthographicCameraController::OrthographicCameraController(const OrthographicCameraControllerSettings &settings)
		: settings(settings)
	{
	}

	void OrthographicCameraController::UpdateCamera(OrthographicCamera &camera, Event &e)
	{
		e.Dispatch([&](WindowResizeEvent &e)
		{
			camera.SetAspectRatio(e.GetSize().GetAspectRatio());
		});
		e.Dispatch([&](MouseScrollEvent &e)
		{
			camera.SetZoomLevel(settings.Bounds.ClampZ(camera.GetZoomLevel() + e.GetOffset().y * settings.ZoomSpeed));
		});
	}

	void OrthographicCameraController::UpdateCamera(OrthographicCamera &camera, const Input &input, float deltaTime)
	{
		UpdateCameraPosition(camera, input, deltaTime);
		UpdateCameraRotation(camera, input, deltaTime);
	}

	void OrthographicCameraController::UpdateCameraPosition(OrthographicCamera &camera, const Input &input, float deltaTime)
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

	void OrthographicCameraController::UpdateCameraRotation(OrthographicCamera &camera, const Input &input, float deltaTime)
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
		camera.SetRotation(glm::mod(rotation, 2.0f * glm::pi<float>()));
	}
}