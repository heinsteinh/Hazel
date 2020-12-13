#pragma once

#include "EntityPanelHelper.h"
#include "EntityNodePopup.h"

namespace Hazel
{
	class EntityNode
	{
	private:
		EntityNodePopup popup;

	public:
		bool WantDestroyEntity() const
		{
			return popup.WantDestroyEntity();
		}

		bool Begin(Entity entity, Entity selectedEntity)
		{
			return ImGui::TreeNodeEx(
				EntityPanelHelper::GetEntityId(entity),
				EntityPanelHelper::GetFlags(entity, selectedEntity),
				EntityPanelHelper::GetTag(entity));
		}

		void Draw(Entity entity, Entity &selectedEntity)
		{
			bool open = Begin(entity, selectedEntity);
			if (ImGui::IsItemClicked())
			{
				selectedEntity = entity;
			}
			popup.Draw(entity);
			if (open)
			{
				End();
			}
		}

		void End()
		{
			ImGui::TreePop();
		}
	};
}