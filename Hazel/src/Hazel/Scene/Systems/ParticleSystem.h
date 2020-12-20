#pragma once

#include "Hazel/Scene/Entity/SceneContext.h"
#include "Hazel/Scene/Components/ParticleComponent.h"

namespace Hazel
{
	class ParticleSystem
	{
	public:
		static void OnUpdate(SceneContext &context)
		{
			auto deltaTime = context.Layer->GetDeltaTime();
			context.Registry.view<ParticleComponent>().each([=](auto entity, auto &component)
			{
				component.UpdateParticles(deltaTime);
			});
		}

		static void OnRender(SceneContext &context)
		{
			context.Registry.view<ParticleComponent>().each([&](auto entity, auto &component)
			{
				component.RenderParticles(*context.Renderer);
			});
		}
	};
}