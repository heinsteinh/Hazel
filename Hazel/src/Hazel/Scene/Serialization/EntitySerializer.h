#pragma once

#include "Hazel/Core/Yaml/YamlSerializer.h"
#include "Hazel/Rendering/Textures/TextureFactory.h"
#include "Hazel/Scene/SceneManager/SceneManager.h"
#include "Hazel/Scene/Scene/Entity.h"
#include "Hazel/Scene/Components/Transform/TransformSerializer.h"

namespace Hazel
{
	class EntitySerializer
	{
	private:
		SceneManager *manager;

	public:
		EntitySerializer(SceneManager &manager)
			: manager(&manager)
		{
		}

		void Serialize(YamlDocument &yaml, Entity entity)
		{
			yaml.BeginMap();
			SerializeHeader(yaml, entity);
			SerializeComponents(yaml, entity);
			yaml.EndMap();
		}

		void Deserialize(const YamlValue &yaml, Entity entity)
		{
			DeserializeHeader(yaml, entity);
			DeserializeComponents(yaml, entity);
		}

	private:
		void SerializeHeader(YamlDocument &yaml, Entity entity)
		{
			yaml.Write("EntityId", entity.GetId())
				.Write("Tag", entity.GetTag())
				.Write("Transform", entity.GetTransform());
		}

		void SerializeComponents(YamlDocument &yaml, Entity entity)
		{
			manager->GetComponentManagers().ForEach([&](auto &componentManager)
			{
				SerializeComponent(yaml, entity, componentManager);
			});
		}

		void SerializeComponent(YamlDocument &yaml, Entity entity, ComponentManager &componentManager)
		{
			if (componentManager.HasComponent(entity))
			{
				yaml.Key().Write(componentManager.GetComponentName()).Value();
				componentManager.SerializeComponent(entity, yaml);
			}
		}

		void DeserializeHeader(const YamlValue &yaml, Entity entity)
		{
			yaml["Tag"].Extract(entity.GetTag());
			yaml["Transform"].Extract(entity.GetTransform());
		}

		void DeserializeComponents(const YamlValue &yaml, Entity entity)
		{
			manager->GetComponentManagers().ForEach([&](auto &componentManager)
			{
				DeserializeComponent(yaml, entity, componentManager);
			});
		}

		void DeserializeComponent(const YamlValue &yaml, Entity entity, ComponentManager &componentManager)
		{
			auto componentYaml = yaml[componentManager.GetComponentName()];
			if (componentYaml.IsValid())
			{
				componentManager.DeserializeComponent(entity, componentYaml);
			}
		}
	};
}