#pragma once

#include "entt/entt.hpp"

namespace Hazel
{
	class SceneCameraHelper
	{
	public:
		static entt::entity GetMainCamera(entt::registry &registry, entt::entity mainCamera);
		static glm::mat4 GetView(entt::registry &registry, entt::entity entity);
		static glm::mat4 GetProjection(entt::registry &registry, entt::entity entity);
	};
}