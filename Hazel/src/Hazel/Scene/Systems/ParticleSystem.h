#pragma once

#include "Hazel/Scene/Scene/Scene.h"
#include "Hazel/Scene/Components/TransformComponent.h"
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
				auto transform = entity.TryGetComponent<TransformComponent>();
				component.Source.AutoEmitParticles(
					transform ? transform->Transform.Translation : glm::vec3(1.0f),
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