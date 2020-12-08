#pragma once

#include "entt/entt.hpp"

#include "SceneInfo.h"
#include "SceneCamera.h"
#include "Hazel/Rendering/Renderer2D.h"
#include "Hazel/Application/Layer.h"

namespace Hazel
{
	class SceneContext
	{
	private:
		Layer *layer = nullptr;
		Renderer2D *renderer = nullptr;
		entt::registry registry;
		SceneCamera sceneCamera;

	public:
		SceneContext(const SceneInfo &info)
			: layer(info.Layer),
			renderer(info.Renderer),
			sceneCamera(registry)
		{
		}

		Layer &GetLayer() const
		{
			return *layer;
		}

		Renderer2D &GetRenderer() const
		{
			return *renderer;
		}

		SceneCamera &GetSceneCamera()
		{
			return sceneCamera;
		}

		const SceneCamera &GetSceneCamera() const
		{
			return sceneCamera;
		}

		entt::registry &GetRegistry()
		{
			return registry;
		}

		const entt::registry &GetRegistry() const
		{
			return registry;
		}
	};
}