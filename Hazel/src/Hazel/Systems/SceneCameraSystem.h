#pragma once

#include "Hazel/Scene/Scene.h"

namespace Hazel
{
	class SceneCameraSystem
	{
	public:
		static Entity GetSceneCamera(Scene &scene);
		static glm::mat4 GetViewProjection(Entity camera);
	};
}