#pragma once

#include "Hazel/Core/Context.h"
#include "OrthographicCamera.h"
#include "Hazel/Events/EventListener.h"

namespace Hazel
{
	class OrthographicCameraController : public EventListener
	{
	private:
		Input &input;
		float aspectRatio = 1.0f;
		float zoomLevel = 1.0f;
		float translationSpeed = 1.0f;
		float rotationSpeed = glm::radians(90.0f);
		bool rotationEnabled = false;
		OrthographicCamera camera;

	public:
		OrthographicCameraController(Context &context);

		constexpr OrthographicCamera &GetCamera()
		{
			return camera;
		}

		constexpr const OrthographicCamera &GetCamera() const
		{
			return camera;
		}

		constexpr float GetTranslationSpeed() const
		{
			return translationSpeed;
		}

		constexpr float GetRotationSpeed() const
		{
			return rotationSpeed;
		}

		constexpr bool HasRotationEnabled() const
		{
			return rotationEnabled;
		}

		constexpr void SetTranslationSpeed(float translationSpeed)
		{
			this->translationSpeed = translationSpeed;
		}

		constexpr void SetRotationSpeed(float rotationSpeed)
		{
			this->rotationSpeed = rotationSpeed;
		}

		constexpr void SetRotationEnabled(bool rotationEnabled)
		{
			this->rotationEnabled = rotationEnabled;
		}

		void OnUpdate(float deltaTime);

		virtual void OnWindowResized(WindowResizeEvent &e) override;
		virtual void OnMouseScrolled(MouseScrollEvent &e) override;

	private:
		void UpdateCameraPosition(float deltaTime);
		void UpdateCameraRotation(float deltaTime);
		void UpdateCameraViewport();
	};
}