#pragma once

#include "RenderApi.h"

namespace Hazel
{
	class AvailableRenderApi
	{
	public:
		static RenderApi &OpenGL;

		AvailableRenderApi() = delete;
	};
}