#pragma once

#include "Hazel/Scene/SceneContext.h"

namespace Hazel
{
	class ParticleSystem
	{
	public:
		static void OnUpdate(SceneContext &context);
		static void OnRender(SceneContext &context);
	};
}