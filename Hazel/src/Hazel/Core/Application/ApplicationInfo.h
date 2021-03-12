#pragma once

#include <string>

#include "glm/glm.hpp"

#include "AvailableGraphicsApi.h"

namespace Hazel
{
	struct ApplicationInfo
	{
		AvailableGraphicsApi GraphicsApi = AvailableGraphicsApi::OpenGL;
		std::string Title = "Hazel";
		glm::vec2 Resolution = {1280.0f, 720.0f};
		bool VerticalSynchronization = true;
		int Samples = 4;
		glm::vec4 ClearColor{0.0f};
		bool GuiEnabled = true;
		bool GuiRenderingEnabled = true;
	};
}