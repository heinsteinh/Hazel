#pragma once

#include <string>

#include "entt/entt.hpp"

#include "Hazel/Core/Camera/Camera.h"
#include "Hazel/Core/Application/Layer.h"

namespace Hazel
{
	struct SceneContext
	{
		std::string Name;
		Layer *Layer = nullptr;
		Camera Camera;
		entt::entity PrimaryCamera = entt::null;
		entt::registry Registry;
	};
}