#pragma once

#include "Hazel/Scene/Scene.h"
#include "TagParser.h"
#include "TransformParser.h"
#include "SpriteParser.h"
#include "CameraParser.h"
#include "ParticleParser.h"
#include "NativeScriptParser.h"

namespace Hazel
{
	class EntityParser
	{
	public:
		static void LoadEntity(const YamlValue &source, Scene &scene)
		{
			if (source.IsValid())
			{
				auto entity = scene.CreateEntity();
				LoadComponent<TagComponent>(source["Tag"], entity);
				LoadComponent<TransformComponent>(source["Transform"], entity);
				LoadComponent<SpriteComponent>(source["Sprite"], entity);
				LoadComponent<CameraComponent>(source["Camera"], entity);
				LoadComponent<ParticleComponent>(source["Particle"], entity);
				LoadComponent<NativeScriptComponent>(source["NativeScript"], entity);
			}
		}

	private:
		template<typename ComponentType>
		static void LoadComponent(const YamlValue &source, Entity entity)
		{
			if (source.IsValid())
			{
				source.Extract(entity.AddComponent<ComponentType>());
			}
		}
	};
}