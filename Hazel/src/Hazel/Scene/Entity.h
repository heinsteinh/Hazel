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
			EntityEvents::OnAddComponent<ComponentType>(*context, *this);
			return component;
		}

		template<typename ComponentType>
		void RemoveComponent()
		{
			EntityEvents::OnRemoveComponent<ComponentType>(*context, *this);
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
		static void OnAddComponent(SceneContext &context, Entity entity)
		{
		}

		template<typename ComponentType>
		static void OnRemoveComponent(SceneContext &context, Entity entity)
		{
		}
	};
}