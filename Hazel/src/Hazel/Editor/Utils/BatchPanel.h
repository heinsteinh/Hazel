#pragma once

#include "Hazel/Rendering/Renderer/RendererInfo.h"
#include "Hazel/Editor/Widgets/InputInt.h"

namespace Hazel
{
	class BatchPanel
	{
	public:
		static bool Draw(RendererInfo &info)
		{
			InputInt::Draw("Index Buffer Size", info.IndexBufferSize);
			InputInt::Draw("Vertex Buffer Size", info.VertexBufferSize);
			InputInt::Draw("Texture Slot Count", info.TextureSlotCount);
			return ImGui::Button("Reset");
		}
	};
}