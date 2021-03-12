#pragma once

#include "glm/glm.hpp"

namespace Hazel
{
	struct WindowInfo
	{
		std::string Title = "Hazel";
		glm::vec2 Resolution = {1280.0f, 720.0f};
	};
}