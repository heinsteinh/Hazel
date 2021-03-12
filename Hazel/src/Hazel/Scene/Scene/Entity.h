#pragma once

#include "entt/entt.hpp"

#include "Hazel/Core/Exceptions/AssertionException.h"
#include "Hazel/Scene/Components/Tag/TagComponent.h"
#include "Hazel/Scene/Components/Transform/TransformComponent.h"

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

		bool IsNull() const
		{
			return entity == entt::null;
		}

		uint32_t GetId() const
		{
			return static_cast<uint32_t>(entity);
		}

		std::string &GetTag() const
		{
			return GetComponent<TagComponent>().Name;
		}

		Transform &GetTransform() const
		{
			return GetComponent<TransformComponent>().Transform;
		}

		template<typename ComponentType>
		bool HasComponent() const
		{
			return registry->has<ComponentType>(entity);
		}

		template<typename ComponentType>
		ComponentType &GetComponent() const
		{
			return registry->get<ComponentType>(entity);
		}

		template<typename ComponentType>
		ComponentType *TryGetComponent() const
		{
			return registry->try_get<ComponentType>(entity);
		}

		template<typename ComponentType, typename ...Args>
		ComponentType &AddComponent(Args &&...args) const
		{
			return registry->get_or_emplace<ComponentType>(entity, std::forward<Args>(args)...);
		}

		template<typename ComponentType>
		void RemoveComponent() const
		{
			registry->remove_if_exists<ComponentType>(entity);
		}

		template<>
		void RemoveComponent<TagComponent>() const
		{
			HZ_ASSERT(false, "Entity must have a tag");
		}

		template<>
		void RemoveComponent<TransformComponent>() const
		{
			HZ_ASSERT(false, "Entity must have a transform");
		}

		bool operator==(const Entity &other) const
		{
			return entity == other.entity && registry == other.registry;
		}

		bool operator!=(const Entity &other) const
		{
			return !(*this == other);
		}

		operator entt::entity() const
		{
			return entity;
		}
	};
}