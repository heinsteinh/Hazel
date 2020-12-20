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

		void Attach(Layer &layer)
		{
			context.Layer = &layer;
		}

		void SetRenderer(Renderer2D &renderer)
		{
			context.Renderer = &renderer;
		}

		Entity GetMainCamera()
		{
			return {context.Camera.GetEntity(), context};
		}

		void SetMainCamera(Entity mainCamera)
		{
			context.Camera.SetEntity(mainCamera, context.Registry);
		}

		const Rectangle &GetViewport() const
		{
			return context.Camera.GetViewport();
		}

		Entity CreateEntity()
		{
			return {context.Registry.create(), context};
		}

		void DestroyEntity(Entity entity)
		{
			context.Registry.destroy(entity);
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