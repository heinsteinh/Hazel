#pragma once

#include "Hazel/Scene/Scene.h"

namespace Hazel
{
	class CameraSystem
	{
	public:
		static Entity GetSceneCamera(Scene &scene);
		static glm::mat4 GetViewProjection(Scene &scene);
		static glm::mat4 GetViewProjection(Entity camera);
	};
}