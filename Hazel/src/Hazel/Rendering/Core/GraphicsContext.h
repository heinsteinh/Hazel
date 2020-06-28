#pragma once

#include "glm/glm.hpp"

#include "Drawer.h"

namespace Hazel
{
	class GraphicsContext
	{
	public:
		virtual ~GraphicsContext() = default;

		virtual void MakeCurrent() = 0;
		virtual void SwapBuffers() = 0;
	};
}