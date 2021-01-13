#pragma once

#include "imgui.h"

#include "Hazel/Rendering/Renderer/RendererInfo.h"

namespace Hazel
{
	class BatchPanel
	{
	public:
		bool Draw(RendererInfo &info)
		{
			int indexBufferSize = static_cast<int>(info.IndexBufferSize);
			int vertexBufferSize = static_cast<int>(info.VertexBufferSize);
			int textureSlotCount = static_cast<int>(info.TextureSlotCount);
			if (ImGui::DragInt("Index Buffer Size", &indexBufferSize, 1.0f, 0, 100000))
			{
				info.IndexBufferSize = indexBufferSize;
			}
			if (ImGui::DragInt("Vertex Buffer Size", &vertexBufferSize, 1.0f, 0, 100000))
			{
				info.VertexBufferSize = vertexBufferSize;
			}
			if (ImGui::DragInt("Texture Slot Count", &textureSlotCount, 1.0f, 0, 128))
			{
				info.TextureSlotCount = textureSlotCount;
			}
			return ImGui::Button("Reset");
		}
	};
}