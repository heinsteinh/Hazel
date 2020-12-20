#pragma once

#include "Hazel/Scene/Context/SceneContext.h"
#include "Hazel/Scene/Components/ParticleComponent.h"

namespace Hazel
{
	class ParticleSystem
	{
	public:
		static void OnUpdate(SceneContext &context)
		{
			auto deltaTime = context.GetLayer().GetDeltaTime();
			context.GetRegistry().view<ParticleComponent>().each([=](auto entity, auto &component)
			{
				component.UpdateParticles(deltaTime);
			});
		}

		static void OnRender(SceneContext &context)
		{
			auto &renderer = context.GetRenderer();
			context.GetRegistry().view<ParticleComponent>().each([&](auto entity, auto &component)
			{
				component.RenderParticles(renderer);
			});
		}
	};
}