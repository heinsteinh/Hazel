#pragma once

#include "imgui.h"

#include "Hazel/Editor/Widgets/TreeNodeSettings.h"

namespace Hazel
{
	class TreeNodeFlags
	{
	public:
		static ImGuiTreeNodeFlags GetFlags(const TreeNodeSettings &settings)
		{
			ImGuiTreeNodeFlags flags = ImGuiTreeNodeFlags_None;
			if (settings.Selected)
			{
				flags |= ImGuiTreeNodeFlags_Selected;
			}
			if (settings.DefaultOpen)
			{
				flags |= ImGuiTreeNodeFlags_DefaultOpen;
			}
			if (settings.OpenOnArrow)
			{
				flags |= ImGuiTreeNodeFlags_OpenOnArrow;
			}
			if (settings.Framed)
			{
				flags |= ImGuiTreeNodeFlags_Framed;
			}
			if (settings.SpanAvailableWidth)
			{
				flags |= ImGuiTreeNodeFlags_SpanAvailWidth;
			}
			return flags;
		}
	};
}