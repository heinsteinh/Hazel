#pragma once

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
		static void Serialize(YamlDocument &document, Entity entity)
		{
			document.BeginMap();
			document.Key().Write("EntityId").Value().Write(entity.GetId());
			Serialize<TagComponent>(document, entity, "Tag");
			Serialize<TransformComponent>(document, entity, "Transform");
			Serialize<SpriteComponent>(document, entity, "Sprite");
			Serialize<CameraComponent>(document, entity, "Camera");
			Serialize<ParticleComponent>(document, entity, "Particle");
			Serialize<NativeScriptComponent>(document, entity, "NativeScript");
			document.EndMap();
		}

		template<typename ComponentType>
		static void Serialize(YamlDocument &document, Entity entity, const char *label)
		{
			auto component = entity.TryGetComponent<ComponentType>();
			if (component)
			{
				document.Key().Write(label).Value().Write(*component);
			}
		}
	};

	template<>
	inline void YamlSerializer::Serialize(YamlDocument &document, const Entity &value)
	{
		EntitySerializer::Serialize(document, value);
	}
}