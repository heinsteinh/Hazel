#pragma once

#include "Hazel/Scene/Entity/Entity.h"
#include "Hazel/Scene/Components/NativeScriptComponent.h"
#include "SceneContext.h"

namespace Hazel
{
	class Scene
	{
	private:
		SceneContext context;

	public:
		Scene(const std::string &name, SceneManagerContext &managerContext)
			: context{name, &managerContext}
		{
		}

		const std::string &GetName() const
		{
			return context.Name;
		}

		void SetName(const std::string &name)
		{
			context.Name = name;
		}

		Layer &GetLayer() const
		{
			return *context.ManagerContext->Layer;
		}

		Renderer2D &GetRenderer() const
		{
			return *context.ManagerContext->Renderer;
		}

		AssetManager &GetAssetManager() const
		{
			return context.ManagerContext->AssetManager;
		}

		Entity GetCameraEntity()
		{
			return {context.CameraEntity, context};
		}

		void SetCameraEntity(Entity primaryCamera)
		{
			context.CameraEntity = primaryCamera;
		}

		const Camera &GetCamera() const
		{
			return context.Camera;
		}

		Camera &GetCamera()
		{
			return context.Camera;
		}

		Entity CreateEntity()
		{
			return {context.Registry.create(), context};
		}

		void DestroyEntity(Entity entity)
		{
			context.Registry.destroy(entity);
		}

		void Clear()
		{
			context.CameraEntity = entt::null;
			context.Registry.clear();
		}

		template<typename FunctorType>
		void ForEach(FunctorType functor)
		{
			context.Registry.each([&](auto entity)
			{
				functor(Entity(entity, context));
			});
		}

		template<typename ComponentType, typename FunctorType>
		void ForEach(FunctorType functor)
		{
			context.Registry.view<ComponentType>().each([&](auto entity, auto &component)
			{
				functor(Entity(entity, context), component);
			});
		}

		template<typename ComponentType, typename FunctorType>
		void Sort(FunctorType functor)
		{
			context.Registry.sort<ComponentType>([&](const entt::entity left, const entt::entity right)
			{
				return functor(Entity(left, context), Entity(right, context));
			}, entt::insertion_sort());
		}

		template<typename ComponentType>
		Entity GetFirstEntityWith()
		{
			auto view = context.Registry.view<ComponentType>();
			return view.empty() ? Entity() : Entity(view.front(), context);
		}
	};
}