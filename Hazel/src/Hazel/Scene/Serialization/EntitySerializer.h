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
			Deserialize<TagComponent>(source["Tag"], value);
			Deserialize<TransformComponent>(source["Transform"], value);
			Deserialize<SpriteComponent>(source["Sprite"], value);
			Deserialize<CameraComponent>(source["Camera"], value);
			Deserialize<ParticleComponent>(source["Particle"], value);
			Deserialize<NativeScriptComponent>(source["NativeScript"], value);
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
		static void Deserialize(const YamlValue &source, Entity entity)
		{
			if (source.IsValid())
			{
				auto &component = entity.AddComponent<ComponentType>();
				source.Extract(component);
				SetupComponent(source, entity, component);
			}
		}

		template<typename ComponentType>
		static void SetupComponent(const YamlValue &source, Entity entity, ComponentType &component)
		{
		}

		static void SetupComponent(const YamlValue &source, Entity entity, SpriteComponent &component)
		{
			auto name = SpriteSerializer::GetTextureName(source);
			if (!name.empty())
			{
				component.Material.Texture = entity.GetAssetManager().GetTexture(name);
			}
		}

		static void SetupComponent(const YamlValue &source, Entity entity, NativeScriptComponent &component)
		{
			auto name = NativeScriptSerializer::GetScriptName(source);
			if (!name.empty())
			{
				component.Script = entity.GetAssetManager().CreateScript(name);
			}
		}
	};

	using EntitySerializer = YamlSerializer<Entity>;
}