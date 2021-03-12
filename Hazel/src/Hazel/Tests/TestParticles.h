#pragma once

#include "Hazel/Scene/Assets/Script.h"
#include "Hazel/Scene/Components/Particle/ParticleComponent.h"

namespace Hazel
{
	class TestParticles : public Script
	{
	public:
		virtual void OnUpdate() override
		{
			auto &input = GetSceneManager().GetInput();
			if (input.IsMouseButtonPressed(MouseButton::B1))
			{
				auto &camera = GetScene().GetCamera();
				auto &position = GetEntity().GetTransform().Translation;
				position = camera.GetWorldPosition(input.GetMousePosition());
			}
		}
	};
}