#pragma once

#include "entt/entt.hpp"

#include "Hazel/Rendering/Renderer2D.h"
#include "Hazel/Application/Layer.h"
#include "Hazel/ParticleSystem/ParticleSystem.h"
#include "Hazel/Camera/CameraProjection.h"

namespace Hazel
{
	struct SceneContext
	{
		entt::entity MainCamera = entt::null;
		CameraProjection CameraProjection;
		Layer *Layer = nullptr;
		Renderer2D *Renderer = nullptr;
		ParticleSystem ParticleSystem;
		entt::registry Registry;
	};
}