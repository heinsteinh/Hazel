#pragma once

#include "imgui.h"

#include "Hazel/Scene/Components/NativeScriptComponent.h"

namespace Hazel
{
	class NativeScriptPanel
	{
	public:
		void Draw(NativeScriptComponent &component)
		{
			if (component.Script)
			{
				ImGui::Text("Type: %s", component.GetTypeName());
				component.Script->OnGui();
			}
		}
	};
}