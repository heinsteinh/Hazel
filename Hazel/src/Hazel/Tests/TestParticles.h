#pragma once

#include "Hazel/Scene/Scripting/NativeScript.h"
#include "Hazel/Scene/Components/TransformComponent.h"
#include "Hazel/Scene/Components/ParticleComponent.h"

namespace Hazel
{
	class TestParticles : public NativeScript
	{
	public:
		virtual void OnUpdate() override
		{
			auto component = TryGetComponent<ParticleComponent>();
			if (!component)
			{
				return;
			}
			auto transform = TryGetComponent<TransformComponent>();
			if (!transform)
			{
				return;
			}
			auto &input = GetInput();
			if (input.IsMouseButtonPressed(Hazel::MouseButton::B1))
			{
				transform->Transform.Translation = GetCamera().GetWorldPosition(input.GetMousePosition());
			}
		}
	};
}