#include "SceneCamera.h"

#include "Hazel/Components/CameraComponent.h"
#include "Hazel/Components/TransformComponent.h"

namespace Hazel
{
	Entity SceneCamera::GetSceneCamera(Scene &scene)
	{
		auto entity = scene.GetMainCamera();
		if (entity.IsValid())
		{
			return entity;
		}
		return scene.GetAllEntitiesWith<CameraComponent>().TryGetFirstEntity();
	}

	glm::mat4 SceneCamera::GetViewProjection(Scene &scene)
	{
		auto entity = GetSceneCamera(scene);
		return entity.IsValid() ? GetViewProjection(entity) : glm::mat4(1.0f);
	}

	glm::mat4 SceneCamera::GetViewProjection(Entity entity)
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