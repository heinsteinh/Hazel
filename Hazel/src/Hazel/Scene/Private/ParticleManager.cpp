#include "ParticleManager.h"

#include "Hazel/Components/ParticleSystemComponent.h"

namespace Hazel
{
	void ParticleManager::OnUpdate(SceneContext &context)
	{
		context.Registry.view<ParticleSystemComponent>().each([&](auto entity, auto &component)
		{
			component.ParticleSystem.UpdateParticles(context.Layer->GetDeltaTime());
		});
	}
}