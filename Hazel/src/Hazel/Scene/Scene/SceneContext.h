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
		entt::entity CameraEntity = entt::null;
		entt::registry Registry;
	};
}