#pragma once

#include "Hazel/Scene/Scripting/NativeScript.h"
#include "Hazel/Scene/Components/ParticleComponent.h"

namespace Hazel
{
	class TestParticles : public NativeScript
	{
	public:
		virtual void OnUpdate() override
		{
			auto &input = GetInput();
			if (input.IsMouseButtonPressed(MouseButton::B1))
			{
				GetTransform().Translation = GetCamera().GetWorldPosition(input.GetMousePosition());
			}
		}
	};
}