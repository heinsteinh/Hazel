#pragma once

#include "Hazel/Rendering/Renderer/RendererStatistics.h"
#include "Hazel/Editor/Widgets/TextBox.h"

namespace Hazel
{
	class RendererStatisticsPanel
	{
	public:
		static void Draw(const RendererStatistics &statistics)
		{
			TextBox::Draw("Draw Call: %zu", statistics.DrawCallCount);
			TextBox::Draw("Vertex: %zu", statistics.VertexCount);
			TextBox::Draw("Index: %zu", statistics.IndexCount);
			TextBox::Draw("Texture Slots: %zu (Max: %zu)", statistics.TextureCount, statistics.TextureSlotCount);
		}
	};
}