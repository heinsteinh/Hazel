#pragma once

#include "imgui.h"

#include "Hazel/BatchRendering/BatchInfo.h"
#include "Hazel/Rendering/RendererStatistics.h"

namespace Hazel
{
	class RendererInfoPanel
	{
	private:
		bool reset = false;

	public:
		void Draw(const char *label, BatchInfo &info, const RendererStatistics &statistics)
		{
			int maxVertexCount = static_cast<int>(info.MaxVertexCount);
			int maxIndexCount = static_cast<int>(info.MaxIndexCount);
			int maxTextureSlotCount = static_cast<int>(info.MaxTextureSlotCount);
			ImGui::Begin(label);
			ImGui::SliderInt("MaxVertexCount", &maxVertexCount, 0, 100000);
			ImGui::SliderInt("MaxIndexCount", &maxIndexCount, 0, 100000);
			ImGui::SliderInt("MaxTextureSlotCount", &maxTextureSlotCount, 0, 128);
			ImGui::Text("DrawCall: %zu", statistics.DrawCallCount);
			ImGui::Text("VertexCount: %zu", statistics.VertexCount);
			ImGui::Text("IndexCount: %zu", statistics.IndexCount);
			ImGui::Text("TextureCount: %zu", statistics.TextureCount);
			reset = ImGui::Button("Reset");
			ImGui::End();
			info.MaxVertexCount = maxVertexCount;
			info.MaxIndexCount = maxIndexCount;
			info.MaxTextureSlotCount = maxTextureSlotCount;
		}

		bool WantReset() const
		{
			return reset;
		}
	};
}