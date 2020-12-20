#include "SceneCameraHelper.h"

#include "Hazel/Scene/Components/CameraComponent.h"
#include "Hazel/Scene/Components/TransformComponent.h"

namespace Hazel
{
	entt::entity SceneCameraHelper::GetCamera(entt::registry &registry, entt::entity camera)
	{
		if (registry.valid(camera) && registry.has<CameraComponent>(camera))
		{
			return camera;
		}
		auto view = registry.view<CameraComponent>();
		if (view.empty())
		{
			return entt::null;
		}
		return view.front();
	}

	glm::mat4 SceneCameraHelper::GetView(entt::registry &registry, entt::entity entity)
	{
		if (entity == entt::null)
		{
			return glm::mat4(1.0f);
		}
		auto transform = registry.try_get<TransformComponent>(entity);
		return transform ? transform->GetView() : glm::mat4(1.0f);
	}

	glm::mat4 SceneCameraHelper::GetProjection(entt::registry &registry, entt::entity entity)
	{
		if (entity == entt::null)
		{
			return glm::mat4(1.0f);
		}
		auto component = registry.try_get<CameraComponent>(entity);
		return component ? component->GetProjection() : glm::mat4(1.0f);
	}
}