#pragma once

#include "imgui.h"

#include "Hazel/Geometry/Rectangle.h"

namespace Hazel
{
	class TextureRegionPanel
	{
	public:
		void Draw(const char *label, Rectangle &textureRegion, const glm::vec2 &textureSize)
		{
			ImGui::Begin("Texture Coordinates");
			ImGui::SliderFloat("Left", &textureRegion.Left, 0.0f, textureSize.x);
			ImGui::SliderFloat("Right", &textureRegion.Right, 0.0f, textureSize.x);
			ImGui::SliderFloat("Bottom", &textureRegion.Bottom, 0.0f, textureSize.y);
			ImGui::SliderFloat("Top", &textureRegion.Top, 0.0f, textureSize.y);
			ImGui::End();
		}
	};
}