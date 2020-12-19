#pragma once

#include "glm/glm.hpp"

#include "Hazel/Rendering/GraphicsApi/GraphicsApi.h"

namespace Hazel
{
	struct WindowInfo
	{
		GraphicsApi *GraphicsApi = nullptr;
		std::string Title = "Hazel";
		glm::vec2 Resolution = {1280.0f, 720.0f};
		bool VerticalSynchronization = true;
	};
}