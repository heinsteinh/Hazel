#include "SceneCamera.h"

#include "Private/SceneCameraHelper.h"
#include "Hazel/Geometry/MvpMatrix.h"
#include "Hazel/Camera/CameraProjection.h"

namespace Hazel
{
	SceneCamera::SceneCamera(entt::registry &registry)
		: registry(&registry)
	{
	}

	void SceneCamera::Update()
	{
		entity = SceneCameraHelper::GetMainCamera(*registry, entity);
		info.View = SceneCameraHelper::GetView(*registry, entity);
		info.Projection = SceneCameraHelper::GetProjection(*registry, entity);
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