#pragma once

#include "Hazel/Scene/Scene/Scene.h"
#include "Hazel/Scene/Components/CameraComponent.h"
#include "Hazel/Scene/Components/TransformComponent.h"

namespace Hazel
{
	class SceneCamera
	{
	public:
		static void UpdatePrimaryCamera(Scene &scene)
		{
			auto camera = scene.GetPrimaryCamera();
			if (!camera.IsValid() || !camera.HasComponent<CameraComponent>())
			{
				scene.SetPrimaryCamera(scene.GetFirstEntityWith<CameraComponent>());
			}
		}

		static glm::mat4 GetViewMatrix(Entity camera)
		{
			if (camera.IsNull())
			{
				return glm::mat4(1.0f);
			}
			auto component = camera.TryGetComponent<TransformComponent>();
			return component ? CameraView::GetViewMatrix(component->Transform) : glm::mat4(1.0f);
		}

		static glm::mat4 GetProjectionMatrix(Entity camera)
		{
			if (camera.IsNull())
			{
				return glm::mat4(1.0f);
			}
			auto component = camera.TryGetComponent<CameraComponent>();
			return component ? component->Projection.ToMatrix() : glm::mat4(1.0f);
		}
	};
}