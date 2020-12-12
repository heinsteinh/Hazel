#pragma once

#include "imgui.h"

#include "Hazel/BatchRendering/BatchInfo.h"

namespace Hazel
{
	class BatchInfoPanel
	{
	public:
		bool Draw(BatchInfo &info)
		{
			bool changed = false;
			int maxVertexCount = static_cast<int>(info.MaxVertexCount);
			int maxIndexCount = static_cast<int>(info.MaxIndexCount);
			int maxTextureSlotCount = static_cast<int>(info.MaxTextureSlotCount);
			if (ImGui::DragInt("Max Vertex", &maxVertexCount, 1.0f, 0, 100000))
			{
				info.MaxVertexCount = maxVertexCount;
				changed = true;
			}
			if (ImGui::DragInt("Max Index", &maxIndexCount, 1.0f, 0, 100000))
			{
				info.MaxIndexCount = maxIndexCount;
				changed = true;
			}
			if (ImGui::DragInt("Max Texture Slots", &maxTextureSlotCount, 1.0f, 0, 128))
			{
				info.MaxTextureSlotCount = maxTextureSlotCount;
				changed = true;
			}
			return changed;
		}
	};
}