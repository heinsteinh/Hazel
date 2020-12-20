#pragma once

#include "yaml-cpp/yaml.h"

#include "Hazel/Scene/Entity/Entity.h"
#include "TagSerializer.h"
#include "TransformSerializer.h"
#include "SpriteSerializer.h"
#include "CameraSerializer.h"
#include "ParticleSerializer.h"
#include "NativeScriptSerializer.h"

namespace Hazel
{
	class EntitySerializer
	{
	public:
		static void Serialize(Entity entity, YAML::Emitter &emitter)
		{
			emitter << YAML::BeginMap;
			emitter << YAML::Key << "Entity" << YAML::Value << entity.GetId();
			SerializeComponent<TagComponent>("Tag", entity, emitter);
			SerializeComponent<TransformComponent>("Transform", entity, emitter);
			SerializeComponent<SpriteComponent>("Sprite", entity, emitter);
			SerializeComponent<CameraComponent>("Camera", entity, emitter);
			SerializeComponent<ParticleComponent>("Particle", entity, emitter);
			SerializeComponent<NativeScriptComponent>("NativeScript", entity, emitter);
			emitter << YAML::EndMap;
		}

	private:
		template<typename ComponentType>
		static void SerializeComponent(const char *name, Entity entity, YAML::Emitter &emitter)
		{
			auto component = entity.TryGetComponent<ComponentType>();
			if (component)
			{
				emitter << YAML::Key << name << YAML::Value << *component;
			}
		}
	};

	inline YAML::Emitter &operator<<(YAML::Emitter &emitter, Entity entity)
	{
		EntitySerializer::Serialize(entity, emitter);
		return emitter;
	}
}