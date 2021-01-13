#pragma once

#include "Hazel/Rendering/GraphicsContext/GraphicsContext.h"

namespace Hazel
{
	struct RendererInfo
	{
		GraphicsContext *GraphicsContext = nullptr;
		size_t UniformBufferSize = 128;
		size_t IndexBufferSize = 240000;
		size_t VertexBufferSize = 400000;
		size_t TextureSlotCount = 32;
	};
}