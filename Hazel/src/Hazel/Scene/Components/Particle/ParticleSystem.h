#pragma once

#include "Hazel/Scene/ComponentSystem/ComponentSystem.h"
#include "ParticleComponent.h"

namespace Hazel
{
	class ParticleSystem : public ComponentSystem
	{
	public:
		virtual void OnUpdate(Scene &scene) override
		{
			scene.ForEach<ParticleComponent>([&](auto entity, auto &component)
			{
				UpdateSourcePosition(entity, component);
				EmitParticles(entity, component);
				UpdateParticles(component);
			});
		}

		virtual void OnRender(Scene &scene) override
		{
			scene.ForEach<ParticleComponent>([&](auto entity, auto &component)
			{
				RenderParticles(component);
			});
		}

	private:
		void UpdateSourcePosition(Entity entity, ParticleComponent &component)
		{
			component.Source.SetPosition(entity.GetTransform().Translation);
		}

		void EmitParticles(Entity entity, ParticleComponent &component)
		{
			component.Source.EmitParticles(GetSceneManager().GetDeltaTime());
		}

		void UpdateParticles(ParticleComponent &component)
		{
			component.Source.UpdateParticles(GetSceneManager().GetDeltaTime());
		}

		void RenderParticles(ParticleComponent &component)
		{
			component.Source.RenderParticles(GetSceneManager().GetRenderer());
		}
	};
}