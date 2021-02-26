#pragma once

#include "Hazel/Scene/Scene/Scene.h"
#include "Hazel/Scene/Components/CameraComponent.h"
#include "Private/SceneCamera.h"

namespace Hazel
{
	class CameraSystem
	{
	public:
		static void OnUpdate(Scene &scene)
		{
			auto cameraEntity = SceneCamera::GetCameraEntity(scene);
			scene.SetCameraEntity(cameraEntity);
			auto &camera = scene.GetCamera();
			camera.SetPosition(SceneCamera::GetPosition(cameraEntity));
			camera.SetViewProjection(
				SceneCamera::GetViewMatrix(cameraEntity),
				SceneCamera::GetProjectionMatrix(cameraEntity));
		}

		static void OnViewportResize(Scene &scene, const Box2D &viewport)
		{
			auto &camera = scene.GetCamera();
			camera.SetViewport(viewport);
			auto aspectRatio = viewport.GetAspectRatio();
			scene.ForEach<CameraComponent>([&](auto entity, auto &component)
			{
				component.Projection.SetAspectRatio(aspectRatio);
			});
		}
	};
}