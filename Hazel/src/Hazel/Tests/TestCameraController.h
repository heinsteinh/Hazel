#pragma once

#include "Hazel/Scene/Scripting/NativeScript.h"
#include "Hazel/Core/Camera/CameraController.h"
#include "Hazel/Scene/Components/CameraComponent.h"
#include "Hazel/Scene/Components/TransformComponent.h"

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
				camera->RecomputeProjection();
			}
			auto transform = TryGetComponent<TransformComponent>();
			if (transform)
			{
				controller.UpdateCameraTransform(transform->Transform, input, deltaTime);
			}
		}
	};
}