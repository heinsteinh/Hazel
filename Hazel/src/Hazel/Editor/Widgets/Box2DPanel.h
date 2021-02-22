#pragma once

#include "imgui.h"

#include "Hazel/Core/Geometry/Box2D.h"

namespace Hazel
{
	class Box2DPanel
	{
	public:
		bool Draw(Box2D &box)
		{
			bool changed = false;
			changed |= ImGui::DragFloat("Left", &box.Min.x);
			changed |= ImGui::DragFloat("Right", &box.Max.x);
			changed |= ImGui::DragFloat("Bottom", &box.Min.y);
			changed |= ImGui::DragFloat("Top", &box.Max.y);
			return changed;
		}
	};
}