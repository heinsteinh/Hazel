#pragma once

#include "Hazel/Scene/Scene/Entity.h"
#include "Hazel/Editor/Widgets/TreeNode.h"
#include "DestroyEntityPopup.h"

namespace Hazel
{
	class EntityNode
	{
	public:
		using Status = DestroyEntityPopup::Status;

		static Status Draw(Entity entity, Entity &selectedEntity)
		{
			bool open = BeginTreeNode(entity, selectedEntity);
			if (TreeNode::IsClicked())
			{
				selectedEntity = entity;
			}
			auto status = DestroyEntityPopup::Draw();
			if (open)
			{
				TreeNode::End();
			}
			return status;
		}

	private:
		static bool BeginTreeNode(Entity entity, Entity selectedEntity)
		{
			TreeNodeSettings settings;
			settings.Selected = entity == selectedEntity;
			settings.OpenOnArrow = true;
			settings.SpanAvailableWidth = true;
			return TreeNode::Begin(entity.GetTag().c_str(), GetEntityId(entity), settings);
		}

		static const void *GetEntityId(Entity entity)
		{
			return reinterpret_cast<const void *>(static_cast<size_t>(entity.GetId()));
		}
	};
}