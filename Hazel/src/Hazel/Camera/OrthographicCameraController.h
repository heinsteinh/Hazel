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

		void OnAttach(OrthographicCamera &camera, const glm::vec2 &windowSize) const;
		void OnEvent(OrthographicCamera &camera, Event &e) const;
		void OnUpdate(OrthographicCamera &camera, const Input &input, float deltaTime) const;

		constexpr OrthographicCameraControllerSettings &GetSettings()
		{
			return settings;
		}

		constexpr const OrthographicCameraControllerSettings &GetSettings() const
		{
			return settings;
		}

	private:
		void UpdateCameraPosition(OrthographicCamera &camera, const Input &input, float deltaTime) const;
		void UpdateCameraRotation(OrthographicCamera &camera, const Input &input, float deltaTime) const;
	};
}