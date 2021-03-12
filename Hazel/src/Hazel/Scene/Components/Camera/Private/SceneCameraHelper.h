#pragma once

#include "Hazel/Scene/Scene/Scene.h"
#include "Hazel/Scene/Components/Camera/CameraComponent.h"

namespace Hazel
{
	class SceneCameraHelper
	{
	public:
		static Entity GetCameraEntity(Scene &scene)
		{
			auto camera = scene.GetCameraEntity();
			if (!camera.IsValid() || !camera.HasComponent<CameraComponent>())
			{
				camera = scene.Find<CameraComponent>();
			}
			return camera;
		}

		static glm::vec3 GetPosition(Entity camera)
		{
			if (camera.IsNull())
			{
				return glm::vec3(0.0f);
			}
			return camera.GetTransform().Translation;
		}

		static glm::mat4 GetViewMatrix(Entity camera)
		{
			if (camera.IsNull())
			{
				return glm::mat4(1.0f);
			}
			return CameraView::GetViewMatrix(camera.GetTransform());
		}

		static glm::mat4 GetProjectionMatrix(Entity camera)
		{
			if (camera.IsNull())
			{
				return glm::mat4(1.0f);
			}
			return camera.GetComponent<CameraComponent>()
				.Projection
				.ToMatrix();
		}

		static void SetAspectRatio(Entity camera, float aspectRatio)
		{
			if (!camera.IsNull())
			{
				camera.GetComponent<CameraComponent>()
					.Projection
					.SetAspectRatio(aspectRatio);
			}
		}
	};
}