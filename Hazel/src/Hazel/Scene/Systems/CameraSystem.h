#pragma once

#include "Hazel/Scene/Entity/SceneContext.h"
#include "Hazel/Scene/Components/CameraComponent.h"

namespace Hazel
{
	class CameraSystem
	{
	public:
		static void OnUpdate(SceneContext &context)
		{
			context.Camera.Update(context.Registry);
		}

		static void OnViewportResize(SceneContext &context, const Rectangle &viewport)
		{
			context.Camera.SetViewport(viewport);
			context.Registry.view<CameraComponent>().each([&](auto entity, auto &component)
			{
				component.SetViewport(viewport);
				component.RecomputeProjection();
			});
		}
	};
}