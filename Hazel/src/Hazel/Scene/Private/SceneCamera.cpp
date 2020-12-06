#include "SceneCamera.h"

#include "Hazel/Components/CameraComponent.h"
#include "Hazel/Components/TransformComponent.h"

namespace Hazel
{
	std::optional<glm::mat4> SceneCamera::GetViewProjection(SceneContext &context)
	{
		auto [entity, camera] = SceneCamera::GetSceneCamera(context);
		if (camera)
		{
			return GetViewProjection(context, entity, *camera);
		}
		return {};
	}

	std::pair<entt::entity, const Camera *> SceneCamera::GetSceneCamera(SceneContext &context)
	{
		if (context.Registry.valid(context.MainCamera))
		{
			return {context.MainCamera, &context.Registry.get<CameraComponent>(context.MainCamera).Camera};
		}
		auto view = context.Registry.view<CameraComponent>();
		if (view.empty())
		{
			return {entt::null, nullptr};
		}
		auto entity = view.front();
		return {entity, &view.get<CameraComponent>(entity).Camera};
	}

	glm::mat4 SceneCamera::GetViewProjection(SceneContext &context, entt::entity entity, const Camera &camera)
	{
		auto transform = context.Registry.try_get<TransformComponent>(entity);
		if (!transform)
		{
			return camera.GetProjection();
		}
		return MvpMatrix::GetViewProjection(transform->GetView(), camera.GetProjection());
	}
}