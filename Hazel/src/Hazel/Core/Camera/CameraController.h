#pragma once

#include "CameraControllerSettings.h"
#include "Camera.h"
#include "Hazel/Core/Geometry/Transform.h"
#include "Hazel/Core/Events/MouseScrollEvent.h"
#include "Hazel/Core/Input/Input.h"

namespace Hazel
{
	class CameraController
	{
	private:
		CameraControllerSettings settings;

	public:
		CameraController(const CameraControllerSettings &settings = {});

		void UpdateCameraProjection(Camera &camera, const Input &input, float deltaTime);
		void UpdateCameraTransform(Transform &transform, const Input &input, float deltaTime);

		CameraControllerSettings &GetSettings()
		{
			return settings;
		}

		const CameraControllerSettings &GetSettings() const
		{
			return settings;
		}

	private:
		float ComputeZoomLevel(Camera &camera, const Input &input, float deltaTime);
		void UpdateCameraPosition(Transform &transform, const Input &input, float deltaTime);
		void UpdateCameraRotation(Transform &transform, const Input &input, float deltaTime);
	};
}