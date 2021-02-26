#pragma once

#include "Hazel/Scene/Entity/Entity.h"
#include "Hazel/Editor/Widgets/Panel.h"
#include "Hazel/Editor/Widgets/TreeNode.h"
#include "Hazel/Editor/Widgets/Spacer.h"
#include "Hazel/Editor/Widgets/Button.h"
#include "RemoveComponentPopup.h"

namespace Hazel
{
	template<typename ComponentType>
	class ComponentNode
	{
	private:
		static inline const void *id = reinterpret_cast<const void *>(typeid(ComponentType).hash_code());

	public:
		static bool Begin(const char *label)
		{
			TreeNodeSettings settings;
			settings.DefaultOpen = true;
			settings.Framed = true;
			return TreeNode::Begin(label, id, settings);
		}

		static void DrawRemoveComponent(Entity entity)
		{
			if (Button::Draw("Remove Component"))
			{
				entity.RemoveComponent<ComponentType>();
			}
		}

		static void End()
		{
			TreeNode::End();
		}
	};
}