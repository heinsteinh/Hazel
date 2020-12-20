#pragma once

#include "entt/entt.hpp"
#include "glm/glm.hpp"

namespace Hazel
{
	class SceneCameraHelper
	{
	public:
		static entt::entity GetCamera(entt::registry &registry, entt::entity camera);
		static glm::mat4 GetView(entt::registry &registry, entt::entity entity);
		static glm::mat4 GetProjection(entt::registry &registry, entt::entity entity);
	};
}