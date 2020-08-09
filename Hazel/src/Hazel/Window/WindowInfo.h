#pragma once

#include "Hazel/Geometry/Size.h"
#include "Hazel/Rendering/RenderApi/AvailableRenderApi.h"

namespace Hazel
{
	struct WindowInfo
	{
		Size Size = {1280.0f, 720.0f};
		std::string Title = "Hazel";
		bool VerticalSynchronization = true;
		RenderApi &RenderApi = AvailableRenderApi::OpenGL;
	};
}