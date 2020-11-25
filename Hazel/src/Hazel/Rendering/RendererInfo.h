#pragma once

#include "Hazel/GraphicsContext/GraphicsContext.h"
#include "Hazel/GraphicsContext/IndexFormatHelper.h"

namespace Hazel
{
	struct RendererInfo
	{
		GraphicsContext *GraphicsContext = nullptr;
		size_t MaxIndexCount = 0;
		size_t MaxVertexCount = 0;
		IndexFormat IndexFormat = IndexFormat::UInt32;
	};
}