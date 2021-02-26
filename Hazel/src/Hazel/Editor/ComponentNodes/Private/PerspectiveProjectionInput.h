#pragma once

#include "imgui.h"

#include "Hazel/Core/Geometry/PerspectiveProjection.h"
#include "Hazel/Editor/Widgets/InputAngle.h"
#include "Hazel/Editor/Widgets/InputFloat.h"

namespace Hazel
{
	class PerspectiveProjectionInput
	{
	public:
		static bool Draw(PerspectiveProjection &projection)
		{
			bool changed = false;
			changed |= InputAngle::Draw("Vertical FOV", projection.VerticalFov);
			changed |= InputFloat::Draw("Near Clip", projection.NearClip);
			changed |= InputFloat::Draw("Far Clip", projection.FarClip);
			return changed;
		}
	};
}