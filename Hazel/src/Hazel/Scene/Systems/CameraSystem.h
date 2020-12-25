#pragma once

#include "Hazel/Scene/Entity/SceneContext.h"
#include "Hazel/Scene/Camera/SceneCamera.h"
#include "Hazel/Scene/Components/CameraComponent.h"

namespace Hazel
{
	class CameraSystem
	{
	public:
		static void OnUpdate(SceneContext &context)
		{
			context.CameraEntity = SceneCamera::GetCameraEntity(context.Registry, context.CameraEntity);
			context.Camera.View = SceneCamera::GetViewMatrix(context.Registry, context.CameraEntity);
			context.Camera.Projection = SceneCamera::GetProjectionMatrix(context.Registry, context.CameraEntity);
			context.Camera.RecomputeViewProjection();
		}

		static void OnViewportResize(SceneContext &context, const Rectangle &viewport)
		{
			context.Camera.Viewport = viewport;
			float aspectRatio = viewport.GetAspectRatio();
			context.Registry.view<CameraComponent>().each([=](auto entity, auto &component)
			{
				component.Projection.SetAspectRatio(aspectRatio);
			});
		}
	};
}