#pragma once

#include "imgui.h"

namespace Hazel
{
	class TreeNodeFlags
	{
	public:
		static ImGuiTreeNodeFlags GetDefaultFlags()
		{
			return ImGuiTreeNodeFlags_DefaultOpen
				| ImGuiTreeNodeFlags_Framed
				| ImGuiTreeNodeFlags_SpanAvailWidth
				| ImGuiTreeNodeFlags_AllowItemOverlap;
		}
	};
}