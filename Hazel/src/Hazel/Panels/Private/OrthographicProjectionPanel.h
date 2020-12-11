#pragma once

#include "imgui.h"

#include "Hazel/Geometry/OrthographicProjection.h"

namespace Hazel
{
	class OrthographicProjectionPanel
	{
	public:
		bool Draw(OrthographicProjection &projection)
		{
			bool changed = false;
			changed |= ImGui::DragFloat("Size", &projection.Size);
			changed |= ImGui::DragFloat("Near Clip", &projection.NearClip);
			changed |= ImGui::DragFloat("Far Clip", &projection.FarClip);
			return changed;
		}
	};
}