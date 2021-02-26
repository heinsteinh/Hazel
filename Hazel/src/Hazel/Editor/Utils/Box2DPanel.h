#pragma once

#include "Hazel/Core/Geometry/Box2D.h"
#include "Hazel/Editor/Widgets/InputFloat.h"

namespace Hazel
{
	class Box2DPanel
	{
	public:
		static bool Draw(Box2D &box)
		{
			bool changed = false;
			changed |= InputFloat::Draw("Left", box.Min.x);
			changed |= InputFloat::Draw("Right", box.Max.x);
			changed |= InputFloat::Draw("Bottom", box.Min.y);
			changed |= InputFloat::Draw("Top", box.Max.y);
			return changed;
		}
	};
}