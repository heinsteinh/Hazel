#pragma once

#include "SceneContext.h"
#include "Hazel/Components/TagComponent.h"
#include "Hazel/Components/CameraComponent.h"
#include "Hazel/Components/TransformComponent.h"
#include "Hazel/Components/SpriteComponent.h"
#include "Hazel/Components/ParticleSourceComponent.h"
#include "Hazel/Components/NativeScriptComponent.h"
#include "Hazel/ComponentPanels/InfoPanel.h"
#include "Hazel/ComponentPanels/RectanglePanel.h"
#include "Hazel/ComponentPanels/BatchInfoPanel.h"
#include "Hazel/ComponentPanels/RendererStatisticsPanel.h"
#include "Hazel/ComponentPanels/TransformPanel.h"
#include "Hazel/Tests/TestCameraController.h"
#include "Hazel/Tests/TestParticles.h"

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