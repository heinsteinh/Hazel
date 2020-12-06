#pragma once

#include "../Entity.h"
#include "Hazel/Camera/Camera.h"

namespace Hazel
{
	class SceneCamera
	{
	public:
		static std::optional<glm::mat4> GetViewProjection(SceneContext &context);

	private:
		static std::pair<entt::entity, const Camera *> GetSceneCamera(SceneContext &context);
		static glm::mat4 GetViewProjection(SceneContext &context, entt::entity entity, const Camera &camera);
	};
}