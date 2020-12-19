#pragma once

#include "entt/entt.hpp"

#include "SceneInfo.h"
#include "SceneCamera.h"
#include "Hazel/Rendering/Renderer2D/Renderer2D.h"
#include "Hazel/Core/Application/Layer.h"

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

		void SetRenderer(Renderer2D &renderer)
		{
			this->renderer = &renderer;
		}

		const Rectangle &GetViewport() const
		{
			return sceneCamera.GetViewport();
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