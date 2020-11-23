#pragma once

#include "Hazel/Graphics/GraphicsApi.h"
#include "Hazel/Geometry/Size.h"

namespace Hazel
{
	struct WindowInfo
	{
		GraphicsApi *GraphicsApi = nullptr;
		std::string Title = "Hazel";
		Size Resolution = {1280.0f, 720.0f};
		bool VerticalSynchronization = true;
	};
}