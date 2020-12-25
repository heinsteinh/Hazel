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
		static void Parse(const YamlValue &source, Scene &scene)
		{
			if (source.IsValid())
			{
				auto entity = scene.CreateEntity();
				ParseComponent<TagComponent>(source["Tag"], entity);
				ParseComponent<TransformComponent>(source["Transform"], entity);
				ParseComponent<SpriteComponent>(source["Sprite"], entity);
				ParseComponent<CameraComponent>(source["Camera"], entity);
				ParseComponent<ParticleComponent>(source["Particle"], entity);
				//ParseComponent<NativeScriptComponent>(source["NativeScript"], entity);
			}
		}

	private:
		template<typename ComponentType>
		static void ParseComponent(const YamlValue &source, Entity entity)
		{
			if (source.IsValid())
			{
				source.Extract(entity.AddComponent<ComponentType>());
			}
		}
	};
}