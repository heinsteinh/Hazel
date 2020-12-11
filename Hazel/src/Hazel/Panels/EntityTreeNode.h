#pragma once

#include "Private/EntityTreeNodeHelper.h"

namespace Hazel
{
	class EntityTreeNode
	{
	public:
		bool Begin(Entity entity, Entity &selectedEntity)
		{
			bool open = ImGui::TreeNodeEx(
				EntityTreeNodeHelper::GetId(entity),
				EntityTreeNodeHelper::GetFlags(entity, selectedEntity),
				EntityTreeNodeHelper::GetTag(entity));
			if (ImGui::IsItemClicked())
			{
				selectedEntity = entity;
			}
			return open;
		}

		void End()
		{
			ImGui::TreePop();
		}
	};
}