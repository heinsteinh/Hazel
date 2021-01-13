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
			auto projection = primaryCamera.TryGetComponent<CameraComponent>();
			auto transform = primaryCamera.TryGetComponent<TransformComponent>();
			camera.SetViewProjection(
				projection ? &projection->Projection : nullptr,
				transform ? &transform->Transform : nullptr);
		}

		static void OnViewportResize(Scene &scene, const Rectangle &viewport)
		{
			scene.GetCamera().SetViewport(viewport);
			auto aspectRatio = viewport.GetAspectRatio();
			scene.ForEach<CameraComponent>([&](auto entity, auto &component)
			{
				component.Projection.SetAspectRatio(aspectRatio);
			});
		}
	};
}