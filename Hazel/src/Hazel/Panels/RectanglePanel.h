#pragma once

#include "imgui.h"

#include "Hazel/Geometry/Rectangle.h"

namespace Hazel
{
	class RectanglePanel
	{
	public:
		void Draw(const char *label, Rectangle &rectangle, const glm::vec2 &maxSize)
		{
			ImGui::Begin(label);
			ImGui::SliderFloat("Left", &rectangle.Left, 0.0f, maxSize.x);
			ImGui::SliderFloat("Right", &rectangle.Right, 0.0f, maxSize.x);
			ImGui::SliderFloat("Bottom", &rectangle.Bottom, 0.0f, maxSize.y);
			ImGui::SliderFloat("Top", &rectangle.Top, 0.0f, maxSize.y);
			ImGui::End();
		}
	};
}