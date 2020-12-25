#pragma once

#include <string>

#include "entt/entt.hpp"

#include "Hazel/Core/Application/Layer.h"
#include "Hazel/Core/Camera/Camera.h"
#include "Hazel/Rendering/Renderer2D/Renderer2D.h"

namespace Hazel
{
	struct SceneContext
	{
		std::string Name;
		Layer *Layer = nullptr;
		Renderer2D *Renderer = nullptr;
		entt::entity CameraEntity = entt::null;
		Camera Camera;
		entt::registry Registry;
	};
}