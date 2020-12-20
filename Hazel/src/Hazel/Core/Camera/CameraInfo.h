#pragma once

#include "glm/glm.hpp"

#include "Hazel/Core/Geometry/Rectangle.h"

namespace Hazel
{
	struct CameraInfo
	{
		Rectangle Viewport;
		glm::mat4 View{1.0f};
		glm::mat4 Projection{1.0f};
		glm::mat4 ViewProjection{1.0f};
	};
}