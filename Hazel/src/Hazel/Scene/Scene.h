#pragma once

#include "SceneManager.h"
#include "SceneContext.h"
#include "Hazel/Components/CameraComponent.h"
#include "Hazel/Components/TransformComponent.h"
#include "Hazel/Components/TextureComponent.h"
#include "Hazel/Components/SpriteComponent.h"
#include "Hazel/UI/TransformUI.h"

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

		void OnUpdate(float deltaTime)
		{
			manager.OnUpdate(context, deltaTime);
		}

		void OnViewportResize(const glm::vec2 &viewport)
		{
			manager.OnViewportResize(context, viewport);
		}
	};
}