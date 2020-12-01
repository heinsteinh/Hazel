#pragma once

namespace Hazel
{
	class Entity
	{
	private:
		entt::entity entity = entt::null;
		entt::registry *registry = nullptr;

	public:
		Entity() = default;

		Entity(entt::entity entity, entt::registry &registry)
			: entity(entity),
			registry(&registry)
		{
		}

		bool IsValid() const
		{
			return registry && registry->valid(entity);
		}

		template<typename ComponentType>
		bool HasComponent() const
		{
			return registry->has<ComponentType>(entity);
		}

		template<typename ComponentType>
		ComponentType &GetComponent()
		{
			return registry->get<ComponentType>(entity);
		}

		template<typename ComponentType>
		ComponentType *TryGetComponent()
		{
			return registry->try_get<ComponentType>(entity);
		}

		template<typename ComponentType, typename...Args>
		ComponentType &AddComponent(Args &&...args)
		{
			return registry->emplace<ComponentType>(entity, std::forward<Args>(args)...);
		}

		template<typename ComponentType>
		void RemoveComponent()
		{
			registry->remove<ComponentType>(entity);
		}

		constexpr operator entt::entity() const
		{
			return entity;
		}
	};
}