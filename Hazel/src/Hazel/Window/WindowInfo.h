#pragma once

#include "Hazel/GraphicsApi/GraphicsApi.h"
#include "Hazel/Geometry/Size.h"

namespace Hazel
{
	struct WindowInfo
	{
		GraphicsApi *GraphicsApi = nullptr;
		std::string Title;
		Size Resolution;
	};
}