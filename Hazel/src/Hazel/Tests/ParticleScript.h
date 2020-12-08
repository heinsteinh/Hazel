#pragma once

#include "Hazel/Scripting/NativeScript.h"
#include "Hazel/Panels/ParticleInfoPanel.h"
#include "Hazel/Camera/CameraProjection.h"
#include "Hazel/Components/CameraComponent.h"
#include "Hazel/Components/TransformComponent.h"
#include "Hazel/Components/ParticleSourceComponent.h"

namespace Hazel
{
	class ParticleScript : public NativeScript
	{
	private:
		ParticleInfo defaultParticleInfo;
		ParticleInfo particleInfo;
		ParticleInfoPanel panel;

	public:
		virtual void OnCreate() override
		{
			defaultParticleInfo.Position = {0.0f, 0.0f};
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
			auto particleSystem = TryGetComponent<ParticleSourceComponent>();
			if (!particleSystem)
			{
				return;
			}
			auto &input = GetInput();
			if (input.IsMouseButtonPressed(Hazel::MouseButton::B1))
			{
				particleInfo.Position = GetCamera().GetWorldPosition(input.GetMousePosition());
				for (int i = 0; i < panel.GetEmissionCount(); i++)
				{
					particleSystem->ParticleSource.EmitParticle(particleInfo);
				}
			}
			auto maxParticleCount = panel.GetMaxParticleCount();
			if (panel.GetMaxParticleCount() != particleSystem->ParticleSource.GetMaxParticleCount())
			{
				particleSystem->ParticleSource.SetMaxParticleCount(maxParticleCount);
			}
		}

		virtual void OnImGuiRender() override
		{
			panel.Draw("Particles", particleInfo);
		}
	};
}