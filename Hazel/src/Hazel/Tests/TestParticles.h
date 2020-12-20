#pragma once

#include "Hazel/Scene/Scripting/NativeScript.h"
#include "Hazel/Scene/Components/TransformComponent.h"
#include "Hazel/Scene/Components/ParticleComponent.h"

namespace Hazel
{
	class TestParticles : public NativeScript
	{
	private:
		int emissionCount = 5;

	public:
		virtual void OnUpdate() override
		{
			auto component = TryGetComponent<ParticleComponent>();
			if (!component)
			{
				return;
			}
			auto &input = GetInput();
			if (input.IsMouseButtonPressed(Hazel::MouseButton::B1))
			{
				component->ParticleInfo.Position = GetCamera().GetWorldPosition(input.GetMousePosition());
				for (int i = 0; i < emissionCount; i++)
				{
					component->EmitParticle();
				}
			}
		}

		virtual void OnGui() override
		{
			ImGui::DragInt("EmissionCount", &emissionCount);
		}
	};
}