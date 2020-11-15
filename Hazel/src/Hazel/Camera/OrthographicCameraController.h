#pragma once

#include "OrthographicCameraControllerSettings.h"
#include "OrthographicCamera.h"
#include "Hazel/Events/Event.h"
#include "Hazel/Input/Input.h"

namespace Hazel
{
	class OrthographicCameraController
	{
	private:
		OrthographicCameraControllerSettings settings;

	public:
		OrthographicCameraController(const OrthographicCameraControllerSettings &settings = {});

		void UpdateCamera(OrthographicCamera &camera, Event &e);
		void UpdateCamera(OrthographicCamera &camera, const Input &input, float deltaTime);

		constexpr OrthographicCameraControllerSettings &GetSettings()
		{
			return settings;
		}

		constexpr const OrthographicCameraControllerSettings &GetSettings() const
		{
			return settings;
		}

	private:
		void UpdateCameraPosition(OrthographicCamera &camera, const Input &input, float deltaTime);
		void UpdateCameraRotation(OrthographicCamera &camera, const Input &input, float deltaTime);
	};
}