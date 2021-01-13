#pragma once

#include "SceneContext.h"
#include "Hazel/Scene/Entity/Entity.h"

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

		TextureManager &GetTextureManager() const
		{
			return *context.ManagerContext->TextureManager;
		}

		ShaderManager &GetShaderManager() const
		{
			return *context.ManagerContext->ShaderManager;
		}

		Entity GetPrimaryCamera()
		{
			return {context.PrimaryCamera, context};
		}

		void SetPrimaryCamera(Entity primaryCamera)
		{
			context.PrimaryCamera = primaryCamera;
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
			context.PrimaryCamera = entt::null;
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

		template<typename ComponentType>
		Entity GetFirstEntityWith()
		{
			auto view = context.Registry.view<ComponentType>();
			return view.empty() ? Entity() : Entity(view.front(), context);
		}
	};
}