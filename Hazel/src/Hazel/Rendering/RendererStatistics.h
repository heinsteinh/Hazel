#pragma once

namespace Hazel
{
	struct RendererStatistics
	{
		size_t DrawCallCount = 0;
		size_t VertexCount = 0;
		size_t MaxVertexCount = 0;
		size_t IndexCount = 0;
		size_t MaxIndexCount = 0;
		size_t UsedTextureSlotCount = 0;
		size_t MaxTextureSlotCount = 0;

		constexpr void Reset()
		{
			DrawCallCount = 0;
			VertexCount = 0;
			IndexCount = 0;
			UsedTextureSlotCount = 0;
		}
	};
}