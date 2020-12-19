#pragma once

#include "Hazel/Scene/Scripting/NativeScript.h"
#include "Hazel/Core/Camera/CameraProjection.h"
#include "Hazel/Scene/Components/TransformComponent.h"
#include "Hazel/Scene/Components/ParticleSourceComponent.h"
#include "Hazel/Editor/ComponentPanels/ParticlePanel.h"

namespace Hazel
{
	class TestParticles : public NativeScript
	{
	private:
		ParticleInfo defaultParticleInfo;
		ParticleInfo particleInfo;
		ParticlePanel panel;

	public:
		virtual void OnCreate() override
		{
			defaultParticleInfo.Position = glm::vec3(0.0f);
			defaultParticleInfo.LinearVelocity = {0.0f, 0.0f};
			defaultParticleInfo.LinearVelocityVariation = {0.2f, 0.2f};
			defaultParticleInfo.AngularVelocity = {3.0f};
			defaultParticleInfo.ColorBegin = {1.0f, 0.30f, 0.0f, 1.0f};
			defaultParticleInfo.ColorEnd = {1.0f, 0.6f, 0.0f, 1.0f};
			defaultParticleInfo.SizeBegin = 0.1f;
			defaultParticleInfo.SizeEnd = 0.0f;
			defaultParticleInfo.SizeVariation = 0.1f;
			defaultParticleInfo.LifeTime = 2.0f;
			particleInfo = defaultParticleInfo;
		}

		virtual void OnUpdate() override
		{
			auto particleSource = TryGetComponent<ParticleSourceComponent>();
			if (!particleSource)
			{
				return;
			}
			auto &input = GetInput();
			if (input.IsMouseButtonPressed(Hazel::MouseButton::B1))
			{
				particleInfo.Position = GetCamera().GetWorldPosition(input.GetMousePosition());
				for (int i = 0; i < panel.GetEmissionCount(); i++)
				{
					particleSource->ParticleSource.EmitParticle(particleInfo);
				}
			}
			auto maxParticleCount = panel.GetMaxParticleCount();
			if (panel.GetMaxParticleCount() != particleSource->ParticleSource.GetMaxParticleCount())
			{
				particleSource->ParticleSource.SetMaxParticleCount(maxParticleCount);
			}
		}

		virtual void OnGui() override
		{
			panel.Draw("Particles", particleInfo);
		}
	};
}