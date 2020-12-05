#pragma once

#include "Script.h"
#include "Hazel/Camera/CameraController.h"
#include "Hazel/Components/CameraComponent.h"
#include "Hazel/Components/TransformComponent.h"

namespace Hazel
{
	class CameraControllerScript : public Script
	{
	private:
		CameraController controller;

	public:
		CameraControllerSettings &GetSettings()
		{
			return controller.GetSettings();
		}

		const CameraControllerSettings &GetSettings() const
		{
			return controller.GetSettings();
		}

		virtual void OnUpdate() override
		{
			auto transform = TryGetComponent<TransformComponent>();
			if (transform)
			{
				controller.UpdateCameraTransform(transform->Transform, GetInput(), GetDeltaTime());
			}
		}

		virtual void OnEvent(Event &e) override
		{
			auto camera = TryGetComponent<CameraComponent>();
			if (camera)
			{
				controller.UpdateCameraProjection(camera->Camera, e);
			}
		}
	};
}