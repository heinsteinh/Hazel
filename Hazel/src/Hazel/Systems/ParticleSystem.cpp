#include "ParticleSystem.h"

#include "Hazel/Components/ParticleSourceComponent.h"

namespace Hazel
{
	void ParticleSystem::OnUpdate(SceneContext &context)
	{
		auto deltaTime = context.GetLayer().GetDeltaTime();
		context.GetRegistry().view<ParticleSourceComponent>().each([=](auto entity, auto &component)
		{
			component.UpdateParticles(deltaTime);
		});
	}

	void ParticleSystem::OnRender(SceneContext &context)
	{
		auto &renderer = context.GetRenderer();
		context.GetRegistry().view<ParticleSourceComponent>().each([&](auto entity, auto &component)
		{
			component.RenderParticles(renderer);
		});
	}
}