#pragma once

#include "imgui.h"

#include "Hazel/Rendering/RendererStatistics.h"

namespace Hazel
{
	class RendererStatisticsPanel
	{
	public:
		void Draw(const RendererStatistics &statistics)
		{
			ImGui::Text("Draw Call: %zu", statistics.DrawCallCount);
			ImGui::Text("Vertex: %zu (Max: %zu)", statistics.VertexCount, statistics.MaxVertexCount);
			ImGui::Text("Index: %zu (Max: %zu)", statistics.IndexCount, statistics.MaxIndexCount);
			ImGui::Text("Texture Slots: %zu (Max: %zu)", statistics.UsedTextureSlotCount, statistics.MaxTextureSlotCount);
		}
	};
}