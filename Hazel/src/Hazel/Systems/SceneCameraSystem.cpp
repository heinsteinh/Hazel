#include "SceneCameraSystem.h"

#include "Hazel/Components/CameraComponent.h"
#include "Hazel/Components/TransformComponent.h"

namespace Hazel
{
	Entity SceneCameraSystem::GetSceneCamera(Scene &scene)
	{
		auto entity = scene.GetMainCamera();
		if (entity.IsValid())
		{
			return entity;
		}
		return scene.GetAllEntitiesWith<CameraComponent>().TryGetFirstEntity();
	}

	glm::mat4 SceneCameraSystem::GetViewProjection(Entity entity)
	{
		auto &camera = entity.GetComponent<CameraComponent>();
		auto transform = entity.TryGetComponent<TransformComponent>();
		if (!transform)
		{
			return camera.GetProjection();
		}
		return MvpMatrix::GetViewProjection(transform->GetView(), camera.GetProjection());
	}
}