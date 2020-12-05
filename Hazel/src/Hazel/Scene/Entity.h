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
			return context && context->Registry.valid(entity);
		}

		SceneContext &GetSceneContext() const
		{
			return *context;
		}

		template<typename ComponentType>
		bool HasComponent() const
		{
			return context->Registry.has<ComponentType>(entity);
		}

		template<typename ComponentType>
		ComponentType &GetComponent()
		{
			return context->Registry.get<ComponentType>(entity);
		}

		template<typename ComponentType>
		ComponentType *TryGetComponent()
		{
			return context->Registry.try_get<ComponentType>(entity);
		}

		template<typename ComponentType, typename...Args>
		ComponentType &AddComponent(Args &&...args)
		{
			auto &component = context->Registry.emplace<ComponentType>(entity, std::forward<Args>(args)...);
			EntityEvents::OnAddComponent<ComponentType>(*this, component);
			return component;
		}

		template<typename ComponentType>
		void RemoveComponent()
		{
			EntityEvents::OnRemoveComponent<ComponentType>(*this);
			context->Registry.remove<ComponentType>(entity);
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
		static void OnAddComponent(Entity entity, ComponentType &component)
		{
		}

		template<typename ComponentType>
		static void OnRemoveComponent(Entity entity)
		{
		}
	};
}