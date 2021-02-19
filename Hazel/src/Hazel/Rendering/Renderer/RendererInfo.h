#pragma once

#include "Hazel/Rendering/GraphicsContext/GraphicsContext.h"
#include "Hazel/Rendering/Mesh/IndexFormat.h"

namespace Hazel
{
	struct RendererInfo
	{
		GraphicsContext *GraphicsContext = nullptr;
		IndexFormat IndexFormat = IndexFormat::UInt16;
		size_t IndexBufferSize = 240000;
		size_t VertexBufferSize = 400000;
		size_t TextureSlotCount = 32;
	};
}