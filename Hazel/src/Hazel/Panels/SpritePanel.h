#pragma once

#include "imgui.h"

#include "Hazel/Components/SpriteComponent.h"
#include "RectanglePanel.h"

namespace Hazel
{
	class SpritePanel
	{
	private:
		RectanglePanel rectanglePanel;

	public:
		void Draw(SpriteComponent &sprite)
		{
			ImGui::ColorEdit4("Color", glm::value_ptr(sprite.Color));
			auto source = sprite.Texture.GetSource();
			if (source)
			{
				ImGui::Text("Source Width: %.0f", source->GetWidth());
				ImGui::Text("Source Height: %.0f", source->GetHeight());
				auto region = sprite.Texture.GetRegion();
				if (rectanglePanel.Draw(region))
				{
					sprite.Texture.SetRegion(region);
				}
			}
		}
	};
}