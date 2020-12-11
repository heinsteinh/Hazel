#pragma once

#include "imgui.h"

#include "Hazel/Geometry/PerspectiveProjection.h"
#include "DragDegrees.h"

namespace Hazel
{
	class PerspectiveProjectionPanel
	{
	private:
		DragDegrees dragDegrees;

	public:
		bool Draw(PerspectiveProjection &projection)
		{
			bool changed = false;
			changed |= dragDegrees.Draw("Vertical FOV", projection.VerticalFov);
			changed |= ImGui::DragFloat("Near Clip", &projection.NearClip);
			changed |= ImGui::DragFloat("Far Clip", &projection.FarClip);
			return changed;
		}
	};
}