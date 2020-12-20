#pragma once

#include "entt/entt.hpp"

#include "Hazel/Core/Application/Layer.h"
#include "Hazel/Rendering/Renderer2D/Renderer2D.h"
#include "Hazel/Scene/Camera/SceneCamera.h"

namespace Hazel
{
	struct SceneContext
	{
		std::string Name;
		Layer *Layer = nullptr;
		Renderer2D *Renderer = nullptr;
		SceneCamera Camera;
		entt::registry Registry;
	};
}