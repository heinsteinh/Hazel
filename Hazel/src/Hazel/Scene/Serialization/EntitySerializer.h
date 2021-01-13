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
	template<>
	struct YamlSerializer<Entity>
	{
		static void Serialize(YamlDocument &document, Entity value)
		{
			document.BeginMap().Write("EntityId", value.GetId());
			Serialize<TagComponent>(document, value, "Tag");
			Serialize<TransformComponent>(document, value, "Transform");
			Serialize<SpriteComponent>(document, value, "Sprite");
			Serialize<CameraComponent>(document, value, "Camera");
			Serialize<ParticleComponent>(document, value, "Particle");
			Serialize<NativeScriptComponent>(document, value, "NativeScript");
			document.EndMap();
		}

		static void Deserialize(const YamlValue &source, Entity value)
		{
			Deserialize<TagComponent>(source, value, "Tag");
			Deserialize<TransformComponent>(source, value, "Transform");
			Deserialize<SpriteComponent>(source, value, "Sprite");
			Deserialize<CameraComponent>(source, value, "Camera");
			Deserialize<ParticleComponent>(source, value, "Particle");
			//Deserialize<NativeScriptComponent>(source, value, "NativeScript");
		}

	private:
		template<typename ComponentType>
		static void Serialize(YamlDocument &document, Entity entity, const char *label)
		{
			auto component = entity.TryGetComponent<ComponentType>();
			if (component)
			{
				document.Write(label, *component);
			}
		}

		template<typename ComponentType>
		static void Deserialize(const YamlValue &source, Entity entity, const char *label)
		{
			auto serializedComponent = source[label];
			if (serializedComponent.IsValid())
			{
				serializedComponent.Extract(entity.AddComponent<ComponentType>());
			}
		}

		template<>
		static void Deserialize<SpriteComponent>(const YamlValue &source, Entity entity, const char *label)
		{
			auto serializedComponent = source[label];
			if (serializedComponent.IsValid())
			{
				auto &component = entity.AddComponent<SpriteComponent>();
				serializedComponent.Extract(component);
				if (!component.TextureFilename.empty())
				{
					component.Material.Texture = entity.GetTextureManager().Load(component.TextureFilename);
				}
			}
		}
	};

	using EntitySerializer = YamlSerializer<Entity>;
}