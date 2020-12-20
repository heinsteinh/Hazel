#pragma once

#include "Hazel/Scene/Context/SceneContext.h"
#include "Hazel/Scene/Entity/Entity.h"
#include "Hazel/Scene/Components/TagComponent.h"
#include "Hazel/Scene/Components/CameraComponent.h"
#include "Hazel/Scene/Components/TransformComponent.h"
#include "Hazel/Scene/Components/SpriteComponent.h"
#include "Hazel/Scene/Components/ParticleSourceComponent.h"
#include "Hazel/Scene/Components/NativeScriptComponent.h"

namespace Hazel
{
	class Scene
	{
	private:
		SceneContext context;

	public:
		Scene(const SceneInfo &info);

		void OnUpdate();
		void OnRender();
		void OnViewportResize(const Rectangle &viewport);
		void OnEvent(Event &e);
		void OnGui();

		void SetRenderer(Renderer2D &renderer)
		{
			context.SetRenderer(renderer);
		}

		Entity GetMainCamera()
		{
			return {context.GetSceneCamera().GetEntity(), context};
		}

		void SetMainCamera(Entity mainCamera)
		{
			context.GetSceneCamera().SetEntity(mainCamera);
		}

		const Rectangle &GetViewport() const
		{
			return context.GetSceneCamera().GetViewport();
		}

		Entity CreateEntity()
		{
			return {context.GetRegistry().create(), context};
		}

		void DestroyEntity(Entity entity)
		{
			context.GetRegistry().destroy(entity);
		}

		template<typename FunctorType>
		void ForEach(FunctorType functor)
		{
			context.GetRegistry().each([&](auto entity)
			{
				functor(Entity(entity, context));
			});
		}
	};
}