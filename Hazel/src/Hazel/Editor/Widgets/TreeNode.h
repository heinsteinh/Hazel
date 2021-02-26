#pragma once

#include "imgui.h"

#include "TreeNodeSettings.h"
#include "Private/TreeNodeFlags.h"

namespace Hazel
{
	class TreeNode
	{
	public:
		static bool Begin(const char *label, const void *id = nullptr, const TreeNodeSettings &settings = {})
		{
			return ImGui::TreeNodeEx(id, TreeNodeFlags::GetFlags(settings), label);
		}

		static bool IsClicked()
		{
			return ImGui::IsItemClicked();
		}

		static void End()
		{
			return ImGui::TreePop();
		}
	};
}