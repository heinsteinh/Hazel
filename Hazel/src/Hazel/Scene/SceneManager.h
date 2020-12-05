#pragma once

#include "SceneRenderer.h"

namespace Hazel
{
	class SceneManager
	{
	private:
		SceneRenderer renderer;

	public:
		void OnUpdate(SceneContext &context, float deltaTime);
		void OnViewportResize(SceneContext &context, const glm::vec2 &viewport);
	};
}