#pragma once

#include "EntityPanelHelper.h"

namespace Hazel
{
	class EntityTreeNode
	{
	public:
		bool Begin(Entity entity, Entity &selectedEntity)
		{
			bool open = ImGui::TreeNodeEx(
				EntityPanelHelper::GetEntityId(entity),
				EntityPanelHelper::GetFlags(entity, selectedEntity),
				EntityPanelHelper::GetTag(entity));
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