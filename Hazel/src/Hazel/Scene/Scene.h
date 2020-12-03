#pragma once

#include "entt/entt.hpp"

#include "EntitySubset.h"

namespace Hazel
{
	class Scene
	{
	private:
		SceneContext context;

	public:
		void OnUpdate(float timestamp);
		void OnViewportResize(const glm::vec2 &viewport);

		Entity CreateEntity()
		{
			return {context.Registry.create(), context};
		}

		void RemoveEntity(Entity entity)
		{
			context.Registry.destroy(entity);
		}

		Entity GetMainCamera()
		{
			return {context.MainCamera, context};
		}

		void SetMainCamera(Entity mainCamera)
		{
			context.MainCamera = mainCamera;
		}

		const glm::vec2 &GetViewport() const
		{
			return context.Viewport;
		}

		Renderer2D &GetRenderer() const
		{
			return *context.Renderer;
		}

		void SetRenderer(Renderer2D &renderer)
		{
			context.Renderer = &renderer;
		}

		template<typename ...ComponentTypes>
		decltype(auto) GetAllEntitiesWith()
		{
			auto entities = context.Registry.view<ComponentTypes...>();
			return EntitySubset<decltype(entities), decltype(entities.begin())>(entities, context);
		}
	};
}