#pragma once

#include "Hazel/Scene/SceneContext.h"

namespace Hazel
{
	class CameraSystem
	{
	public:
		static void OnUpdate(SceneContext &context);
		static void OnViewportResize(SceneContext &context, const Rectangle &viewport);
	};
}