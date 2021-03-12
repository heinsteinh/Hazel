#pragma once

#include "ComponentManager.h"

namespace Hazel
{
	template<typename ComponentType>
	class BaseComponentManager : public ComponentManager
	{
	public:
		BaseComponentManager(const std::string &componentName)
			: ComponentManager(componentName)
		{
		}

		virtual bool HasComponent(Entity entity) override
		{
			return entity.HasComponent<ComponentType>();
		}

		virtual void AddComponent(Entity entity) override
		{
			entity.AddComponent<ComponentType>();
		}

		virtual void RemoveComponent(Entity entity) override
		{
			entity.RemoveComponent<ComponentType>();
		}
	};
}