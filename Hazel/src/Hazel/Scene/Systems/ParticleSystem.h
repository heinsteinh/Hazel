#pragma once

#include "Hazel/Scene/Entity/SceneContext.h"
#include "Hazel/Scene/Components/TransformComponent.h"
#include "Hazel/Scene/Components/ParticleComponent.h"

namespace Hazel
{
	class ParticleSystem
	{
	public:
		static void OnUpdate(SceneContext &context)
		{
			auto deltaTime = context.Layer->GetDeltaTime();
			context.Registry.view<ParticleComponent>().each([&](auto entity, auto &component)
			{
				auto transform = context.Registry.try_get<TransformComponent>(entity);
				component.UpdateParticles(
					transform ? transform->Transform.Translation : glm::vec3(0.0f),
					deltaTime);
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