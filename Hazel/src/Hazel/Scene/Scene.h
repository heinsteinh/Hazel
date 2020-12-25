#pragma once

#include "Hazel/Scene/Entity/Entity.h"
#include "Hazel/Scene/Components/TagComponent.h"
#include "Hazel/Scene/Components/CameraComponent.h"
#include "Hazel/Scene/Components/TransformComponent.h"
#include "Hazel/Scene/Components/SpriteComponent.h"
#include "Hazel/Scene/Components/ParticleComponent.h"
#include "Hazel/Scene/Components/NativeScriptComponent.h"

namespace Hazel
{
	class Scene
	{
	private:
		SceneContext context;

	public:
		Scene(const std::string &name);

		void OnUpdate();
		void OnRender();
		void OnViewportResize(const Rectangle &viewport);
		void OnEvent(Event &e);

		const std::string &GetName() const
		{
			return context.Name;
		}

		void SetName(const std::string &name)
		{
			context.Name = name;
		}

		void Attach(Layer &layer)
		{
			context.Layer = &layer;
		}

		void SetRenderer(Renderer2D &renderer)
		{
			context.Renderer = &renderer;
		}

		Entity GetPrimaryCamera()
		{
			return {context.PrimaryCamera, context};
		}

		void SetPrimaryCamera(Entity primaryCamera)
		{
			context.PrimaryCamera = primaryCamera;
		}

		const Rectangle &GetViewport() const
		{
			return context.Camera.Viewport;
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
	};
}