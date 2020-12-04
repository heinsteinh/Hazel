#include "Scene.h"

#include "Hazel/Systems/CameraSystem.h"
#include "Hazel/Systems/SpriteRenderSystem.h"
#include "Hazel/Components/CameraComponent.h"

namespace Hazel
{
	void Scene::OnUpdate(float timestamp)
	{
		auto camera = CameraSystem::GetSceneCamera(*this);
		if (camera.IsValid())
		{
			context.Renderer->BeginScene(CameraSystem::GetViewProjection(camera));
			SpriteRenderSystem::RenderSprites(*this);
			context.Renderer->EndScene();
		}
	}

	void Scene::OnViewportResize(const glm::vec2 &viewport)
	{
		for (auto entity : GetAllEntitiesWith<CameraComponent>())
		{
			entity.GetComponent<CameraComponent>().OnViewportResize(viewport);
		}
	}
}