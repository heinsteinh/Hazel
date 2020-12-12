#pragma once

#include "imgui.h"

#include "Hazel/Geometry/Rectangle.h"

namespace Hazel
{
	class RectanglePanel
	{
	public:
		void Draw(Rectangle &rectangle)
		{
			ImGui::DragFloat("Left", &rectangle.Left);
			ImGui::DragFloat("Right", &rectangle.Right);
			ImGui::DragFloat("Bottom", &rectangle.Bottom);
			ImGui::DragFloat("Top", &rectangle.Top);
		}
	};
}