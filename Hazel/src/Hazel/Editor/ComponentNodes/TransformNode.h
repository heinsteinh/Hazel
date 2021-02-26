#pragma once

#include "Hazel/Scene/Entity/Entity.h"
#include "Hazel/Scene/Components/TransformComponent.h"
#include "Hazel/Editor/Widgets/InputAngle.h"

namespace Hazel
{
	class TransformNode
	{
	public:
		static void Draw(Entity entity, TransformComponent &component)
		{
			Draw(component.Transform);
		}

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