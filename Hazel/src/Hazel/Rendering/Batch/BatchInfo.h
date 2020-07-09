#pragma once

#include "Hazel/Rendering/Core/RenderApiFactory.h"

namespace Hazel
{
	struct BatchInfo
	{
		RenderApiFactory &Factory;
		size_t MaxVertices = 0;
		size_t MaxIndices = 0;
		size_t MaxTextures = 0;
	};
}