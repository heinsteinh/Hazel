#pragma once

#include "entt/entt.hpp"

#include "Hazel/Rendering/Renderer2D.h"
#include "Hazel/Application/Layer.h"
#include "Hazel/ParticleSystem/ParticleSystem.h"

namespace Hazel
{
	struct SceneContext
	{
		entt::entity MainCamera = entt::null;
		glm::vec2 Viewport{0.0f};
		Layer *Layer = nullptr;
		Renderer2D *Renderer = nullptr;
		ParticleSystem ParticleSystem;
		entt::registry Registry;
	};
}