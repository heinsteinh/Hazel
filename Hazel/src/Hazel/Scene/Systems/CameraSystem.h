#pragma once

#include "Hazel/Scene/Scene/SceneContext.h"
#include "Hazel/Scene/Components/CameraComponent.h"

namespace Hazel
{
	class CameraSystem
	{
	public:
		static void OnUpdate(SceneContext &context)
		{
			context.GetSceneCamera().Update();
		}

		static void OnViewportResize(SceneContext &context, const Rectangle &viewport)
		{
			context.GetSceneCamera().SetViewport(viewport);
			context.GetRegistry().view<CameraComponent>().each([&](auto entity, auto &component)
			{
				component.SetViewport(viewport);
			});
		}
	};
}