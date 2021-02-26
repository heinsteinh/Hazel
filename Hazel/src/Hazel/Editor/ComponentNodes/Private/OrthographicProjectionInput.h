#pragma once

#include "imgui.h"

#include "Hazel/Core/Geometry/OrthographicProjection.h"
#include "Hazel/Editor/Widgets/InputFloat.h"

namespace Hazel
{
	class OrthographicProjectionInput
	{
	public:
		static bool Draw(OrthographicProjection &projection)
		{
			bool changed = false;
			changed |= InputFloat::Draw("Size", projection.Size);
			changed |= InputFloat::Draw("Near Clip", projection.NearClip);
			changed |= InputFloat::Draw("Far Clip", projection.FarClip);
			return changed;
		}
	};
}