#pragma once

#include "Hazel/Scene/Assets/Script.h"
#include "CameraController.h"
#include "Controller.h"
#include "Hazel/Scene/Components/Camera/CameraComponent.h"

namespace Hazel
{
	class TestCameraController : public Script
	{
	private:
		Controller controller;
		CameraController cameraController;

	public:
		virtual void OnUpdate() override
		{
			auto context = GetSceneManager();
			auto entity = GetEntity();
			auto deltaTime = context.GetDeltaTime();
			auto &input = context.GetInput();
			auto camera = entity.TryGetComponent<CameraComponent>();
			if (camera)
			{
				cameraController.UpdateProjection(camera->Projection, input, deltaTime);
			}
			controller.UpdateTransform(entity.GetTransform(), input, deltaTime);
		}
	};
}