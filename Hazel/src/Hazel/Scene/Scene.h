#pragma once

#include "SceneContext.h"
#include "Hazel/Components/CameraComponent.h"
#include "Hazel/Components/TransformComponent.h"
#include "Hazel/Components/TextureComponent.h"
#include "Hazel/Components/SpriteComponent.h"
#include "Hazel/Components/ParticleSourceComponent.h"
#include "Hazel/Components/NativeScriptComponent.h"
#include "Hazel/Panels/InfoPanel.h"
#include "Hazel/Panels/TextureRegionPanel.h"
#include "Hazel/Panels/RendererInfoPanel.h"
#include "Hazel/Panels/TransformPanel.h"
#include "Hazel/Tests/CameraControllerScript.h"
#include "Hazel/Tests/ParticleScript.h"

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
		void OnImGuiRender();

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

		void RemoveEntity(Entity entity)
		{
			context.GetRegistry().destroy(entity);
		}
	};
}