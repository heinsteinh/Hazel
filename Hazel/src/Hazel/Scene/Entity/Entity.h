#pragma once

#include "Hazel/Core/Exceptions/AssertionException.h"
#include "Hazel/Scene/Context/SceneContext.h"
#include "EntityListener.h"

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
			HZ_ASSERT(context, "Invalid entity");
			return *context;
		}

		template<typename ComponentType>
		bool HasComponent() const
		{
			HZ_ASSERT(IsValid(), "Invalid entity");
			return context->GetRegistry().has<ComponentType>(entity);
		}

		template<typename ComponentType>
		ComponentType &GetComponent()
		{
			HZ_ASSERT(IsValid(), "Invalid entity");
			HZ_ASSERT(HasComponent<ComponentType>(), "Cannot get non-existing component.");
			return context->GetRegistry().get<ComponentType>(entity);
		}

		template<typename ComponentType>
		ComponentType *TryGetComponent()
		{
			HZ_ASSERT(IsValid(), "Invalid entity");
			return context->GetRegistry().try_get<ComponentType>(entity);
		}

		template<typename ComponentType, typename ...Args>
		ComponentType &AddComponent(Args &&...args)
		{
			HZ_ASSERT(IsValid(), "Invalid entity");
			HZ_ASSERT(!HasComponent<ComponentType>(), "Already has component.");
			auto &component = context->GetRegistry().emplace<ComponentType>(entity, std::forward<Args>(args)...);
			EntityListener::OnComponentAdded<ComponentType>(*this, component);
			return component;
		}

		template<typename ComponentType>
		void RemoveComponent()
		{
			HZ_ASSERT(IsValid(), "Invalid entity");
			HZ_ASSERT(HasComponent<ComponentType>(), "Cannot remove non-existing component.");
			EntityListener::OnComponentRemoved<ComponentType>(*this);
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
}