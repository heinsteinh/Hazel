#pragma once

#include "Hazel/Scripting/NativeScript.h"
#include "Hazel/Camera/CameraController.h"
#include "Hazel/Components/CameraComponent.h"
#include "Hazel/Components/TransformComponent.h"

namespace Hazel
{
	class TestCameraController : public NativeScript
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
			auto deltaTime = GetDeltaTime();
			auto &input = GetInput();
			auto camera = TryGetComponent<CameraComponent>();
			if (camera)
			{
				controller.UpdateCameraProjection(camera->Camera, input, deltaTime);
			}
			auto transform = TryGetComponent<TransformComponent>();
			if (transform)
			{
				controller.UpdateCameraTransform(transform->Transform, input, deltaTime);
			}
		}
	};
}