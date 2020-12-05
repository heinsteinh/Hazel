#pragma once

#include "CameraControllerSettings.h"
#include "Camera.h"
#include "Hazel/Geometry/Transform.h"
#include "Hazel/Events/MouseScrollEvent.h"
#include "Hazel/Input/Input.h"

namespace Hazel
{
	class CameraController
	{
	private:
		CameraControllerSettings settings;

	public:
		CameraController(const CameraControllerSettings &settings = {});

		void UpdateCameraProjection(Camera &camera, Event &e);
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
		float ComputeZoomLevel(Camera &camera, MouseScrollEvent &e);
		void UpdateCameraPosition(Transform &transform, const Input &input, float deltaTime);
		void UpdateCameraRotation(Transform &transform, const Input &input, float deltaTime);
	};
}