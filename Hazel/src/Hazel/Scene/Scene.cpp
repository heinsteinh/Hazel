#include "Scene.h"

#include "SceneCamera.h"
#include "SpriteRenderer.h"
#include "Hazel/Components/CameraComponent.h"

namespace Hazel
{
	void Scene::OnUpdate(float timestamp)
	{
		auto camera = SceneCamera::GetSceneCamera(*this);
		if (camera.IsValid())
		{
			context.Renderer->BeginScene(SceneCamera::GetViewProjection(camera));
			renderer.RenderSprites(*this);
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