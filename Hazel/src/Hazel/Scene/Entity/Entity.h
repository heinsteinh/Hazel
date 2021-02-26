#pragma once

#include <type_traits>

#include "entt/entt.hpp"

#include "Hazel/Scene/Scene/SceneContext.h"
#include "Hazel/Scene/Components/TagComponent.h"
#include "Hazel/Scene/Components/TransformComponent.h"
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

		std::string &GetTag() const
		{
			return GetComponent<TagComponent>().Name;
		}

		Transform &GetTransform() const
		{
			return GetComponent<TransformComponent>().Transform;
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
		ComponentType &GetComponent() const
		{
			return context->Registry.get<ComponentType>(entity);
		}

		template<typename ComponentType>
		ComponentType *TryGetComponent() const
		{
			return context->Registry.try_get<ComponentType>(entity);
		}

		template<typename ComponentType, typename ...Args>
		ComponentType &AddComponent(Args &&...args) const
		{
			auto &component = context->Registry.emplace<ComponentType>(entity, std::forward<Args>(args)...);
			EntityListener::OnComponentAdded(*this, component);
			return component;
		}

		template<typename ComponentType>
		void RemoveComponent() const
		{
			EntityListener::OnComponentRemoved<ComponentType>(*this);
			context->Registry.remove<ComponentType>(entity);
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