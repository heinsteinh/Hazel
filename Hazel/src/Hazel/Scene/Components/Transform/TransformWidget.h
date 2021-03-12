#pragma once

#include "Hazel/Core/Geometry/Transform.h"
#include "Hazel/Editor/Widgets/InputAngle.h"
#include "Hazel/Editor/Widgets/InputFloat.h"

namespace Hazel
{
	class TransformWidget
	{
	public:
		static void Draw(Transform &transform)
		{
			InputFloatSettings settings;
			settings.Speed = 0.1f;
			InputFloat::Draw("Translation", transform.Translation, settings);
			InputAngle::Draw("Rotation", transform.Rotation);
			InputFloat::Draw("Scale", transform.Scale, settings);
		}
	};
}