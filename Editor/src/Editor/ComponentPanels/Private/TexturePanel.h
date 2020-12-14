#pragma once

#include "imgui.h"

#include "Hazel/Textures/SubTexture.h"

#include "RectanglePanel.h"

namespace Hazel
{
	class TexturePanel
	{
	private:
		RectanglePanel rectanglePanel;

	public:
		void Draw(SubTexture &texture)
		{
			DrawSource(texture);
			ImGui::Text("Region");
			DrawRegion(texture);
		}

		void DrawSource(SubTexture &texture)
		{
			auto source = texture.GetSource();
			if (source)
			{
				ImGui::Text("Source Width: %.0f", source->GetWidth());
				ImGui::Text("Source Height: %.0f", source->GetHeight());
			}
		}

		void DrawRegion(SubTexture &texture)
		{
			auto region = texture.GetRegion();
			if (rectanglePanel.Draw(region))
			{
				texture.SetRegion(region);
			}
		}
	};
}