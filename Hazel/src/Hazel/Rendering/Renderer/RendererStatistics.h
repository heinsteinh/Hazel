#pragma once

#include "RendererInfo.h"

namespace Hazel
{
	struct RendererStatistics
	{
		size_t DrawCallCount = 0;
		size_t VertexCount = 0;
		size_t IndexCount = 0;
		size_t TextureCount = 0;
		size_t UniformBufferSize = 0;
		size_t IndexBufferSize = 0;
		size_t VertexBufferSize = 0;
		size_t TextureSlotCount = 0;

		constexpr RendererStatistics() = default;

		constexpr RendererStatistics(const RendererInfo &info)
			: UniformBufferSize(info.UniformBufferSize),
			IndexBufferSize(info.IndexBufferSize),
			VertexBufferSize(info.VertexBufferSize),
			TextureSlotCount(info.TextureSlotCount)
		{
		}

		constexpr void Reset()
		{
			DrawCallCount = 0;
			VertexCount = 0;
			IndexCount = 0;
			TextureCount = 0;
		}
	};
}