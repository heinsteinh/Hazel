#pragma once

#include "entt/entt.hpp"

#include "Hazel/Rendering/Renderer2D.h"

namespace Hazel
{
	struct SceneContext
	{
		entt::entity MainCamera = entt::null;
		glm::vec2 Viewport{0.0f};
		Renderer2D *Renderer = nullptr;
		entt::registry Registry;
	};
}