#pragma once

#include "Hazel/Scene/Scene/Entity.h"
#include "Hazel/Editor/Widgets/Panel.h"
#include "Hazel/Editor/Widgets/TreeNode.h"
#include "Hazel/Editor/Widgets/Spacer.h"
#include "Hazel/Editor/Widgets/Button.h"
#include "RemoveComponentPopup.h"

namespace Hazel
{
	class ComponentNode
	{
	public:
		static bool Begin(const char *label)
		{
			TreeNodeSettings settings;
			settings.DefaultOpen = true;
			settings.Framed = true;
			return TreeNode::Begin(label, label, settings);
		}

		static bool DrawRemoveComponent()
		{
			return Button::Draw("Remove Component");
		}

		static void End()
		{
			TreeNode::End();
		}
	};
}