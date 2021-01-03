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
			SceneCamera::UpdatePrimaryCamera(scene);
			auto primaryCamera = scene.GetPrimaryCamera();
			auto &camera = scene.GetCamera();
			camera.View = SceneCamera::GetViewMatrix(primaryCamera);
			camera.Projection = SceneCamera::GetProjectionMatrix(primaryCamera);
			camera.RecomputeViewProjection();
		}

		static void OnViewportResize(Scene &scene, const Rectangle &viewport)
		{
			scene.GetCamera().Viewport = viewport;
			auto aspectRatio = viewport.GetAspectRatio();
			scene.ForEach<CameraComponent>([&](auto entity, auto &component)
			{
				component.Projection.SetAspectRatio(aspectRatio);
			});
		}
	};
}