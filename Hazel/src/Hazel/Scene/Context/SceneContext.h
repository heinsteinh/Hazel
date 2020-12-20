#pragma once

#include "entt/entt.hpp"

#include "SceneInfo.h"
#include "Hazel/Rendering/Renderer2D/Renderer2D.h"
#include "Hazel/Core/Application/Layer.h"
#include "Hazel/Scene/Camera/SceneCamera.h"
#include "Hazel/Core/Exceptions/AssertionException.h"

namespace Hazel
{
	class SceneContext
	{
	private:
		std::string name;
		Layer *layer = nullptr;
		Renderer2D *renderer = nullptr;
		entt::registry registry;
		SceneCamera sceneCamera;

	public:
		SceneContext(const SceneInfo &info)
			: name(info.Name),
			layer(info.Layer),
			renderer(info.Renderer),
			sceneCamera(registry)
		{
			HZ_ASSERT(info.Layer && info.Renderer, "A scene needs to be attached to an application and a renderer.")
		}

		const std::string &GetName() const
		{
			return name;
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

		entt::registry &GetRegistry()
		{
			return registry;
		}

		const entt::registry &GetRegistry() const
		{
			return registry;
		}

		SceneCamera &GetSceneCamera()
		{
			return sceneCamera;
		}

		const SceneCamera &GetSceneCamera() const
		{
			return sceneCamera;
		}
	};
}