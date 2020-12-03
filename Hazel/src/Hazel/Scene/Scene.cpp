#include "Scene.h"

#include "Hazel/Systems/SceneCameraSystem.h"
#include "Hazel/Systems/SpriteRenderSystem.h"
#include "Hazel/Components/CameraComponent.h"

namespace Hazel
{
	void Scene::OnUpdate(float timestamp)
	{
		auto camera = SceneCameraSystem::GetSceneCamera(*this);
		if (camera.IsValid())
		{
			context.Renderer->BeginScene(SceneCameraSystem::GetViewProjection(camera));
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