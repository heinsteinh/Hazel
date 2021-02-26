#pragma once

#include "Hazel/Scene/Scene/Scene.h"
#include "Hazel/Scene/Components/ParticleComponent.h"

namespace Hazel
{
	class ParticleSystem
	{
	public:
		static void OnUpdate(Scene &scene)
		{
			auto deltaTime = scene.GetLayer().GetDeltaTime();
			scene.ForEach<ParticleComponent>([&](auto entity, auto &component)
			{
				component.Source.AutoEmitParticles(
					entity.GetTransform().Translation,
					component.Info,
					deltaTime);
				component.Source.UpdateParticles(deltaTime);
			});
		}

		static void OnRender(Scene &scene)
		{
			scene.ForEach<ParticleComponent>([&](auto entity, auto &component)
			{
				component.Source.RenderParticles(scene.GetRenderer());
			});
		}
	};
}