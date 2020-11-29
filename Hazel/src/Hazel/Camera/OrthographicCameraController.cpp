#include "OrthographicCameraController.h"

#include "Hazel/Events/WindowResizeEvent.h"
#include "Hazel/Events/MouseScrollEvent.h"
#include "Hazel/Geometry/Size.h"

namespace Hazel
{
	OrthographicCameraController::OrthographicCameraController(const OrthographicCameraControllerSettings &settings)
		: settings(settings)
	{
	}

	void OrthographicCameraController::OnAttach(OrthographicCamera &camera, const glm::vec2 &windowSize) const
	{
		camera.SetWindowSize(windowSize);
	}

	void OrthographicCameraController::OnEvent(OrthographicCamera &camera, Event &e) const
	{
		e.Dispatch([&](WindowResizeEvent &e)
		{
			camera.SetWindowSize(e.GetWindowSize());
		});
		e.Dispatch([&](MouseScrollEvent &e)
		{
			camera.SetZoomLevel(settings.Bounds.ClampZ(camera.GetZoomLevel() - settings.ZoomSpeed * e.GetOffset().y));
		});
	}

	void OrthographicCameraController::OnUpdate(OrthographicCamera &camera, const Input &input, float deltaTime) const
	{
		UpdateCameraPosition(camera, input, deltaTime);
		UpdateCameraRotation(camera, input, deltaTime);
	}

	void OrthographicCameraController::UpdateCameraPosition(OrthographicCamera &camera, const Input &input, float deltaTime) const
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
		if (position != camera.GetPosition())
		{
			camera.SetPosition(settings.Bounds.Clamp(position));
		}
	}

	void OrthographicCameraController::UpdateCameraRotation(OrthographicCamera &camera, const Input &input, float deltaTime) const
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
		if (rotation != camera.GetRotation())
		{
			camera.SetRotation(glm::mod(rotation, 2.0f * glm::pi<float>()));
		}
	}
}