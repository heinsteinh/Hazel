#pragma once

#include "EntityTreeNode.h"

namespace Hazel
{
	class EntityPanel
	{
	private:
		EntityTreeNode node;

	public:
		void Draw(Entity entity, Entity &selectedEntity)
		{
			if (node.Begin(entity, selectedEntity))
			{
				node.End();
			}
		}
	};
}