#pragma once

#include "imgui.h"

#include "Hazel/Rendering/Renderer2D/RendererInfo.h"

namespace Hazel
{
	class BatchPanel
	{
	public:
		bool Draw(RendererInfo &info)
		{
			int maxVertexCount = static_cast<int>(info.MaxVertexCount);
			int maxIndexCount = static_cast<int>(info.MaxIndexCount);
			int maxTextureSlotCount = static_cast<int>(info.MaxTextureSlotCount);
			if (ImGui::DragInt("Max Vertex Count", &maxVertexCount, 1.0f, 0, 100000))
			{
				info.MaxVertexCount = maxVertexCount;
			}
			if (ImGui::DragInt("Max Index Count", &maxIndexCount, 1.0f, 0, 100000))
			{
				info.MaxIndexCount = maxIndexCount;
			}
			if (ImGui::DragInt("Max Texture Slots", &maxTextureSlotCount, 1.0f, 0, 128))
			{
				info.MaxTextureSlotCount = maxTextureSlotCount;
			}
			return ImGui::Button("Reset");
		}
	};
}