#pragma once

#include "../SceneContext.h"

namespace Hazel
{
	class CameraManager
	{
	public:
		static void OnUpdate(SceneContext &context);
		static void OnViewportResize(SceneContext &context, const glm::vec2 &viewport);
	};
}