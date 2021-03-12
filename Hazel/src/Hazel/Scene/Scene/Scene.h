#pragma once

#include <string>

#include "entt/entt.hpp"

#include "Hazel/Core/Camera/Camera.h"
#include "Hazel/Scene/Components/Tag/TagComponent.h"
#include "Hazel/Scene/Components/Transform/TransformComponent.h"
#include "Entity.h"

namespace Hazel
{
	class Scene
	{
	private:
		std::string name;
		Camera camera;
		entt::entity cameraEntity = entt::null;
		entt::registry registry;

	public:
		Scene(const std::string &name)
			: name(name)
		{
		}

		const std::string &GetName() const
		{
			return name;
		}

		void SetName(const std::string &name)
		{
			this->name = name;
		}

		Entity GetCameraEntity()
		{
			return {cameraEntity, registry};
		}

		void SetCameraEntity(Entity cameraEntity)
		{
			this->cameraEntity = cameraEntity;
		}

		const Camera &GetCamera() const
		{
			return camera;
		}

		Camera &GetCamera()
		{
			return camera;
		}

		Entity CreateEntity(const std::string &name = {})
		{
			Entity entity(registry.create(), registry);
			entity.AddComponent<TagComponent>(name);
			entity.AddComponent<TransformComponent>();
			return entity;
		}

		void DestroyEntity(Entity entity)
		{
			registry.destroy(entity);
		}

		void Clear()
		{
			cameraEntity = entt::null;
			registry.clear();
		}

		template<typename FunctorType>
		void ForEach(FunctorType functor)
		{
			registry.each([&](auto entity)
			{
				functor(Entity(entity, registry));
			});
		}

		template<typename ComponentType, typename FunctorType>
		void ForEach(FunctorType functor)
		{
			registry.view<ComponentType>().each([&](auto entity, auto &component)
			{
				functor(Entity(entity, registry), component);
			});
		}

		template<typename ComponentType>
		Entity Find()
		{
			auto view = registry.view<ComponentType>();
			return view.empty() ? Entity() : Entity(view.front(), registry);
		}
	};
}