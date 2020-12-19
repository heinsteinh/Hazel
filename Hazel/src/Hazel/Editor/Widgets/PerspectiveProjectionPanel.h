#pragma once

#include "imgui.h"

#include "Hazel/Core/Geometry/PerspectiveProjection.h"

#include "Hazel/Editor/Widgets/AngleInput.h"
#include "Hazel/Editor/Widgets/FloatInput.h"

namespace Hazel
{
	class PerspectiveProjectionPanel
	{
	private:
		AngleInput angleInput;
		FloatInput floatInput;

	public:
		bool Draw(PerspectiveProjection &projection)
		{
			bool changed = false;
			changed |= angleInput.Draw("Vertical FOV", projection.VerticalFov);
			changed |= floatInput.Draw("Near Clip", projection.NearClip);
			changed |= floatInput.Draw("Far Clip", projection.FarClip);
			return changed;
		}
	};
}