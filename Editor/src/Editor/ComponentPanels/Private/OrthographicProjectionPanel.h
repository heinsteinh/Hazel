#pragma once

#include "imgui.h"

#include "Hazel/Geometry/OrthographicProjection.h"

#include "Editor/Widgets/FloatInput.h"

namespace Hazel
{
	class OrthographicProjectionPanel
	{
	private:
		FloatInput input;

	public:
		bool Draw(OrthographicProjection &projection)
		{
			bool changed = false;
			changed |= input.Draw("Size", projection.Size);
			changed |= input.Draw("Near Clip", projection.NearClip);
			changed |= input.Draw("Far Clip", projection.FarClip);
			return changed;
		}
	};
}