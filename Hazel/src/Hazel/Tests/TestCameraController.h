#pragma once

#include "Hazel/Scene/Scripting/NativeScript.h"
#include "CameraController.h"
#include "Controller.h"
#include "Hazel/Scene/Components/CameraComponent.h"
#include "Hazel/Scene/Components/TransformComponent.h"

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
				cameraController.Update(camera->Projection, input, deltaTime);
			}
			auto transform = TryGetComponent<TransformComponent>();
			if (transform)
			{
				controller.Update(transform->Transform, input, deltaTime);
			}
		}
	};
}