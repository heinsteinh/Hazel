#pragma once

#include <string>

#include "Hazel/Core/Yaml/YamlSerializer.h"
#include "Hazel/Scene/Scene/Entity.h"
#include "Hazel/Scene/SceneManager/SceneManagerView.h"

namespace Hazel
{
	class ComponentManager
	{
	private:
		std::string componentName;
		SceneManagerView manager;

	public:
		ComponentManager(const std::string &componentName)
			: componentName(componentName)
		{
		}

		const std::string &GetComponentName() const
		{
			return componentName;
		}

		SceneManagerView GetSceneManager() const
		{
			return manager;
		}

		void Attach(SceneManagerView manager)
		{
			this->manager = manager;
			OnAttach();
		}

		virtual bool HasComponent(Entity entity) = 0;
		virtual void AddComponent(Entity entity) = 0;
		virtual void RemoveComponent(Entity entity) = 0;
		virtual void DrawComponent(Entity entity) = 0;
		virtual void SerializeComponent(Entity entity, YamlDocument &yaml) = 0;
		virtual void DeserializeComponent(Entity entity, const YamlValue &yaml) = 0;

		virtual void OnAttach()
		{
		}
	};
}