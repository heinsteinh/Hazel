#pragma once

#include "Hazel/Utils/Size.h"

namespace Hazel
{
	struct WindowInfo
	{
		Size Dimensions = {1280.0f, 720.0f};
		std::string Title = "Hazel";
		bool VerticalSynchronization = true;
	};
}