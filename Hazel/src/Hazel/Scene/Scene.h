#pragma once

#include "SceneView.h"

namespace Hazel
{
	class Scene
	{
	private:
		entt::registry registry;

	public:
		Entity CreateEntity()
		{
			return {registry.create(), registry};
		}

		void RemoveEntity(Entity entity)
		{
			registry.destroy(entity);
		}

		template<typename ...ComponentTypes>
		decltype(auto) GetAllEntitiesWith()
		{
			auto view = registry.view<ComponentTypes...>();
			return SceneView<decltype(view), decltype(view.begin())>(view, registry);
		}
	};
}