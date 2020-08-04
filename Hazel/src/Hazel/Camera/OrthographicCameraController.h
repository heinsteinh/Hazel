#pragma once

#include "Hazel/Events/EventListener.h"
#include "Hazel/Input/Input.h"
#include "OrthographicCameraControllerSettings.h"
#include "OrthographicCamera.h"

namespace Hazel
{
	class OrthographicCameraController : public EventListener
	{
	private:
		Input &input;
		OrthographicCamera &camera;
		OrthographicCameraControllerSettings settings;

	public:
		OrthographicCameraController(Input &input, OrthographicCamera &camera);

		void OnUpdate(float deltaTime);

		virtual void OnWindowResized(WindowResizeEvent &e) override;
		virtual void OnMouseScrolled(MouseScrollEvent &e) override;

		constexpr OrthographicCameraControllerSettings &GetSettings()
		{
			return settings;
		}

		constexpr const OrthographicCameraControllerSettings &GetSettings() const
		{
			return settings;
		}

	private:
		void UpdateCameraPosition(float deltaTime);
		void UpdateCameraRotation(float deltaTime);
	};
}