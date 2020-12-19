#include "CameraController.h"

#include "Hazel/Core/Events/WindowResizeEvent.h"
#include "Hazel/Core/Events/MouseScrollEvent.h"
#include "Hazel/Core/Geometry/Size.h"

namespace Hazel
{
	CameraController::CameraController(const CameraControllerSettings &settings)
		: settings(settings)
	{
	}

	void CameraController::UpdateCameraProjection(Camera &camera, const Input &input, float deltaTime)
	{
		camera.SetZoomLevel(settings.Bounds.ClampZ(ComputeZoomLevel(camera, input, deltaTime)));
	}

	void CameraController::UpdateCameraTransform(Transform &transform, const Input &input, float deltaTime)
	{
		UpdateCameraPosition(transform, input, deltaTime);
		UpdateCameraRotation(transform, input, deltaTime);
	}

	float CameraController::ComputeZoomLevel(Camera &camera, const Input &input, float deltaTime)
	{
		return camera.GetZoomLevel() - settings.ZoomSpeed * input.GetMouseScrollOffset().y;
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