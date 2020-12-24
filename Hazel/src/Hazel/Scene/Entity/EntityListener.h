#pragma once

namespace Hazel
{
	class Entity;

	struct EntityListener
	{
		template<typename ComponentType>
		static void OnComponentAdded(Entity entity, ComponentType &component)
		{
		}

		template<typename ComponentType>
		static void OnComponentRemoved(Entity entity)
		{
		}
	};
}