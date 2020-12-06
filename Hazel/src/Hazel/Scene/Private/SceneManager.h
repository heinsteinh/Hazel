#pragma once

#include "SceneRenderer.h"

namespace Hazel
{
	class SceneManager
	{
	private:
		SceneRenderer renderer;

	public:
		void OnUpdate(SceneContext &context);
		void OnViewportResize(SceneContext &context, const glm::vec2 &viewport);
		void OnEvent(SceneContext &context, Event &e);
		void OnImGuiRender(SceneContext &context);
	};
}