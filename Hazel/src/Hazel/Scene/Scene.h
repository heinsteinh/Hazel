#pragma once

#include "Private/SceneManager.h"
#include "SceneContext.h"
#include "Hazel/Components/CameraComponent.h"
#include "Hazel/Components/TransformComponent.h"
#include "Hazel/Components/TextureComponent.h"
#include "Hazel/Components/SpriteComponent.h"
#include "Hazel/Components/NativeScriptComponent.h"
#include "Hazel/Scripting/CameraControllerScript.h"
#include "Hazel/Panels/InfoPanel.h"
#include "Hazel/Panels/TextureRegionPanel.h"
#include "Hazel/Panels/RendererInfoPanel.h"
#include "Hazel/Panels/TransformPanel.h"

namespace Hazel
{
	class Scene
	{
	private:
		SceneManager manager;
		SceneContext context;

	public:
		Entity GetMainCamera()
		{
			return {context.MainCamera, context};
		}

		void SetMainCamera(Entity mainCamera)
		{
			context.MainCamera = mainCamera;
		}

		const glm::vec2 &GetViewport() const
		{
			return context.Viewport;
		}

		void SetLayer(Layer &layer)
		{
			context.Layer = &layer;
		}

		void SetRenderer(Renderer2D &renderer)
		{
			context.Renderer = &renderer;
		}

		Entity CreateEntity()
		{
			return {context.Registry.create(), context};
		}

		void RemoveEntity(Entity entity)
		{
			context.Registry.destroy(entity);
		}

		void OnUpdate()
		{
			manager.OnUpdate(context);
		}

		void OnViewportResize(const glm::vec2 &viewport)
		{
			manager.OnViewportResize(context, viewport);
		}

		void OnEvent(Event &e)
		{
			manager.OnEvent(context, e);
		}
	};
}