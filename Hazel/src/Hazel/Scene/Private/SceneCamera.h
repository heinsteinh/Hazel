#pragma once

#include "../SceneContext.h"

namespace Hazel
{
	class SceneCamera
	{
	public:
		static entt::entity GetSceneCamera(SceneContext &context);
		static glm::mat4 GetView(SceneContext &context, entt::entity camera);
		static glm::mat4 GetProjection(SceneContext &context, entt::entity camera);
	};
}