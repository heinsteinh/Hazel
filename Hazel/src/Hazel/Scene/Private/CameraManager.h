#pragma once

#include "../SceneContext.h"

namespace Hazel
{
	class CameraManager
	{
	public:
		static void OnViewportResize(SceneContext &context, const glm::vec2 &viewport);
	};
}