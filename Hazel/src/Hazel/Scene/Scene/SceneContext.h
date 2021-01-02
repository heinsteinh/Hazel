#pragma once

#include <string>

#include "entt/entt.hpp"

#include "Hazel/Core/Camera/Camera.h"
#include "Hazel/Scene/Manager/SceneManagerContext.h"

namespace Hazel
{
	struct SceneContext
	{
		std::string Name;
		SceneManagerContext *ManagerContext = nullptr;
		Camera Camera;
		entt::entity PrimaryCamera = entt::null;
		entt::registry Registry;
	};
}