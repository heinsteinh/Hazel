#pragma once

#include "imgui.h"

#include "Hazel/Geometry/Rectangle.h"

namespace Hazel
{
	class RectanglePanel
	{
	public:
		bool Draw(Rectangle &rectangle)
		{
			bool changed = false;
			changed |= ImGui::DragFloat("Left", &rectangle.Left);
			changed |= ImGui::DragFloat("Right", &rectangle.Right);
			changed |= ImGui::DragFloat("Bottom", &rectangle.Bottom);
			changed |= ImGui::DragFloat("Top", &rectangle.Top);
			return changed;
		}
	};
}