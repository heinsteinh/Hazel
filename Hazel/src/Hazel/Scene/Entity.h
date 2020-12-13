#pragma once

#include "SceneContext.h"

namespace Hazel
{
	class Entity
	{
	private:
		entt::entity entity = entt::null;
		SceneContext *context = nullptr;

	public:
		Entity() = default;

		Entity(entt::entity entity, SceneContext &context)
			: entity(entity),
			context(&context)
		{
		}

		bool IsValid() const
		{
			return context && context->GetRegistry().valid(entity);
		}

		bool IsNull() const
		{
			return entity == entt::null;
		}

		uint32_t GetId() const
		{
			return static_cast<uint32_t>(entity);
		}

		SceneContext &GetSceneContext() const
		{
			return *context;
		}

		template<typename ComponentType>
		bool HasComponent() const
		{
			return context->GetRegistry().has<ComponentType>(entity);
		}

		template<typename ComponentType>
		ComponentType &GetComponent()
		{
			return context->GetRegistry().get<ComponentType>(entity);
		}

		template<typename ComponentType>
		ComponentType *TryGetComponent()
		{
			return context->GetRegistry().try_get<ComponentType>(entity);
		}

		template<typename ComponentType, typename ...Args>
		ComponentType &AddComponent(Args &&...args)
		{
			auto &component = context->GetRegistry().emplace<ComponentType>(entity, std::forward<Args>(args)...);
			EntityEvents::OnComponentAdded<ComponentType>(*this, component);
			return component;
		}

		template<typename ComponentType>
		void RemoveComponent()
		{
			EntityEvents::OnComponentRemoved<ComponentType>(*this);
			context->GetRegistry().remove<ComponentType>(entity);
		}

		bool operator==(const Entity &other) const
		{
			return entity == other.entity && context == other.context;
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

	class EntityEvents
	{
	public:
		template<typename ComponentType>
		static void OnComponentAdded(Entity entity, ComponentType &component)
		{
		}

		template<typename ComponentType>
		static void OnComponentRemoved(Entity entity)
		{
		}
	};
}