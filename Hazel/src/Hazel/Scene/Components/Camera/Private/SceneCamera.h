#pragma once

#include "Hazel/Scene/Scene/Scene.h"
#include "SceneCameraHelper.h"

namespace Hazel
{
	class SceneCamera
	{
	public:
		static void UpdateCamera(Scene &scene)
		{
			UpdateCameraEntity(scene);
			UpdateCameraPosition(scene);
			UpdateCameraViewProjection(scene);
			UpdateCameraEntityAspectRatio(scene);
		}

		static void UpdateCameraViewport(Scene &scene, const Box2D &viewport)
		{
			scene.GetCamera().SetViewport(viewport);
		}

	private:
		static void UpdateCameraEntity(Scene &scene)
		{
			scene.SetCameraEntity(SceneCameraHelper::GetCameraEntity(scene));
		}

		static void UpdateCameraPosition(Scene &scene)
		{
			scene.GetCamera().SetPosition(
				SceneCameraHelper::GetPosition(scene.GetCameraEntity()));
		}

		static void UpdateCameraViewProjection(Scene &scene)
		{
			auto cameraEntity = scene.GetCameraEntity();
			scene.GetCamera().SetViewProjection(
				SceneCameraHelper::GetViewMatrix(cameraEntity),
				SceneCameraHelper::GetProjectionMatrix(cameraEntity));
		}

		static void UpdateCameraEntityAspectRatio(Scene &scene)
		{
			SceneCameraHelper::SetAspectRatio(
				scene.GetCameraEntity(),
				scene.GetCamera().GetAspectRatio());
		}
	};
}