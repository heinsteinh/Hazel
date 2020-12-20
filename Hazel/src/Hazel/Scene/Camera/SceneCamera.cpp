#include "SceneCamera.h"

#include "Private/SceneCameraHelper.h"
#include "Hazel/Core/Geometry/MvpMatrix.h"
#include "Hazel/Core/Camera/CameraProjection.h"

namespace Hazel
{
	void SceneCamera::Update(entt::registry &registry)
	{
		entity = SceneCameraHelper::GetCamera(registry, entity);
		info.View = SceneCameraHelper::GetView(registry, entity);
		info.Projection = SceneCameraHelper::GetProjection(registry, entity);
		info.ViewProjection = MvpMatrix::GetViewProjection(info.View, info.Projection);
	}

	glm::vec3 SceneCamera::GetWorldPosition(const glm::vec2 &screenPosition) const
	{
		return CameraProjection::GetWorldPosition(info, screenPosition);
	}

	glm::vec2 SceneCamera::GetScreenPosition(const glm::vec3 &worldPosition) const
	{
		return CameraProjection::GetScreenPosition(info, worldPosition);
	}
}