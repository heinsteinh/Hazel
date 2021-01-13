#pragma once

#include "imgui.h"

#include "Hazel/Rendering/Renderer/RendererStatistics.h"

namespace Hazel
{
	class RendererStatisticsPanel
	{
	public:
		void Draw(const RendererStatistics &statistics)
		{
			ImGui::Text("Draw Call: %zu", statistics.DrawCallCount);
			ImGui::Text("Vertex: %zu", statistics.VertexCount);
			ImGui::Text("Index: %zu", statistics.IndexCount);
			ImGui::Text("Texture Slots: %zu (Max: %zu)", statistics.TextureCount, statistics.TextureSlotCount);
		}
	};
}