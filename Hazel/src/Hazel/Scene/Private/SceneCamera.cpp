#include "SceneCamera.h"

#include "Hazel/Components/CameraComponent.h"
#include "Hazel/Components/TransformComponent.h"

namespace Hazel
{
	entt::entity SceneCamera::GetSceneCamera(SceneContext &context)
	{
		if (context.Registry.valid(context.MainCamera))
		{
			return context.MainCamera;
		}
		auto view = context.Registry.view<CameraComponent>();
		if (view.empty())
		{
			return entt::null;
		}
		return view.front();
	}

	glm::mat4 SceneCamera::GetView(SceneContext &context, entt::entity camera)
	{
		if (camera == entt::null)
		{
			return glm::mat4(1.0f);
		}
		auto transform = context.Registry.try_get<TransformComponent>(camera);
		return transform ? transform->GetView() : glm::mat4(1.0f);
	}

	glm::mat4 SceneCamera::GetProjection(SceneContext &context, entt::entity camera)
	{
		if (camera == entt::null)
		{
			return glm::mat4(1.0f);
		}
		auto component = context.Registry.try_get<CameraComponent>(camera);
		return component ? component->GetProjection() : glm::mat4(1.0f);
	}
}