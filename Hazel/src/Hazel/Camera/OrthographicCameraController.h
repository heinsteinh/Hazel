#pragma once

#include "Hazel/Events/EventListener.h"
#include "OrthographicCameraControllerInfo.h"

namespace Hazel
{
	class OrthographicCameraController : public EventListener
	{
	private:
		Input &input;
		OrthographicCameraControllerSettings settings;
		OrthographicCamera &camera;

	public:
		OrthographicCameraController(const OrthographicCameraControllerInfo &info);

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

		constexpr const OrthographicCamera &GetCamera() const
		{
			return camera;
		}

	private:
		void UpdateCameraPosition(float deltaTime);
		void UpdateCameraRotation(float deltaTime);
	};
}