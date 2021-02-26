#pragma once

#include "Hazel/Scene/Entity/Entity.h"
#include "Hazel/Editor/Widgets/Panel.h"
#include "Hazel/Editor/Widgets/TreeNode.h"
#include "Hazel/Editor/Widgets/Spacer.h"
#include "Hazel/Editor/Widgets/Button.h"
#include "RemoveComponentPopup.h"

namespace Hazel
{
	template<typename ComponentType, typename PanelType>
	class ComponentNode
	{
	private:
		static inline const void *id = reinterpret_cast<const void *>(typeid(ComponentType).hash_code());

	public:
		static void Draw(const char *label, Entity entity)
		{
			auto component = entity.TryGetComponent<ComponentType>();
			if (component && BeginTreeNode(label))
			{
				DrawComponent(entity, *component);
				TreeNode::End();
			}
		}

		static void Draw(Entity entity)
		{
			auto component = entity.TryGetComponent<ComponentType>();
			if (component)
			{
				DrawComponent(entity, *component);
			}
		}

	private:
		static bool BeginTreeNode(const char *label)
		{
			TreeNodeSettings settings;
			settings.DefaultOpen = true;
			settings.Framed = true;
			return TreeNode::Begin(label, id, settings);
		}

		static void DrawComponent(Entity entity, ComponentType &component)
		{
			PanelType::Draw(entity, component);
			if (Button::Draw("Remove Component"))
			{
				entity.RemoveComponent<ComponentType>();
			}
		}
	};
}