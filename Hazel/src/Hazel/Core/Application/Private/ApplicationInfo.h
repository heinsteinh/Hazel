#pragma once

#include "glm/glm.hpp"

#include "Hazel/Rendering/GraphicsApi/AvailableGraphicsApi.h"
#include "Hazel/Core/Window/WindowInfo.h"

namespace Hazel
{
	struct ApplicationInfo
	{
		AvailableGraphicsApi GraphicsApi = AvailableGraphicsApi::OpenGL;
		WindowInfo WindowInfo;
		glm::vec4 ClearColor{0.0f};
	};
}