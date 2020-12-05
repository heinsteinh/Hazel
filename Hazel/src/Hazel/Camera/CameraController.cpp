#include "CameraController.h"

#include "Hazel/Events/WindowResizeEvent.h"
#include "Hazel/Events/MouseScrollEvent.h"
#include "Hazel/Geometry/Size.h"

namespace Hazel
{
	CameraController::CameraController(const CameraControllerSettings &settings)
		: settings(settings)
	{
	}

	void CameraController::UpdateCameraProjection(Camera &camera, Event &e)
	{
		e.Dispatch([&](MouseScrollEvent &e)
		{
			camera.SetZoomLevel(settings.Bounds.ClampZ(ComputeZoomLevel(camera, e)));
		});
	}

	void CameraController::UpdateCameraTransform(Transform &transform, const Input &input, float deltaTime)
	{
		UpdateCameraPosition(transform, input, deltaTime);
		UpdateCameraRotation(transform, input, deltaTime);
	}

	float CameraController::ComputeZoomLevel(Camera &camera, MouseScrollEvent &e)
	{
		return camera.GetZoomLevel() - settings.ZoomSpeed * e.GetOffset().y;
	}

	void CameraController::UpdateCameraPosition(Transform &transform, const Input &input, float deltaTime)
	{
		auto deltaPosition = settings.TranslationSpeed * deltaTime;
		if (input.IsKeyPressed(settings.Up))
		{
			transform.Translation.y += deltaPosition;
		}
		if (input.IsKeyPressed(settings.Down))
		{
			transform.Translation.y -= deltaPosition;
		}
		if (input.IsKeyPressed(settings.Right))
		{
			transform.Translation.x += deltaPosition;
		}
		if (input.IsKeyPressed(settings.Left))
		{
			transform.Translation.x -= deltaPosition;
		}
		transform.Translation = settings.Bounds.Clamp(transform.Translation);
	}

	void CameraController::UpdateCameraRotation(Transform &transform, const Input &input, float deltaTime)
	{
		auto rotation = glm::eulerAngles(transform.Rotation);
		auto deltaRotation = settings.RotationSpeed * deltaTime;
		if (input.IsKeyPressed(settings.ClockwiseRotation))
		{
			rotation.z -= deltaRotation;
		}
		if (input.IsKeyPressed(settings.CounterClockwiseRotation))
		{
			rotation.z += deltaRotation;
		}
		rotation.z = glm::mod(rotation.z, 2.0f * glm::pi<float>());
		transform.Rotation = glm::quat(rotation);
	}
}