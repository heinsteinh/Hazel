#pragma once

#include "entt/entt.hpp"

#include "Hazel/Scene/Scene/SceneContext.h"
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
			return context && context->Registry.valid(entity);
		}

		bool IsNull() const
		{
			return entity == entt::null;
		}

		uint32_t GetId() const
		{
			return static_cast<uint32_t>(entity);
		}

		Layer &GetLayer() const
		{
			return *context->ManagerContext->Layer;
		}

		Renderer2D &GetRenderer() const
		{
			return *context->ManagerContext->Renderer;
		}

		AssetManager &GetAssetManager() const
		{
			return context->ManagerContext->AssetManager;
		}

		const Camera &GetCamera() const
		{
			return context->Camera;
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

		template<typename ComponentType, typename ...Args>
		ComponentType &AddComponent(Args &&...args)
		{
			auto &component = context->Registry.emplace<ComponentType>(entity, std::forward<Args>(args)...);
			EntityListener::OnComponentAdded(*this, component);
			return component;
		}

		template<typename ComponentType>
		void RemoveComponent()
		{
			EntityListener::OnComponentRemoved<ComponentType>(*this);
			context->Registry.remove<ComponentType>(entity);
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