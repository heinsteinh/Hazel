#pragma once

#include "Hazel/Scene/Scripting/NativeScript.h"
#include "CameraController.h"
#include "Controller.h"
#include "Hazel/Scene/Components/CameraComponent.h"

namespace Hazel
{
	class TestCameraController : public NativeScript
	{
	private:
		Controller controller;
		CameraController cameraController;

	public:
		virtual void OnUpdate() override
		{
			auto deltaTime = GetDeltaTime();
			auto &input = GetInput();
			auto camera = TryGetComponent<CameraComponent>();
			if (camera)
			{
				cameraController.UpdateProjection(camera->Projection, input, deltaTime);
			}
			controller.UpdateTransform(GetTransform(), input, deltaTime);
		}
	};
}