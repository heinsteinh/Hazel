#pragma once

#include "imgui.h"

#include "Hazel/Scene/Components/NativeScriptComponent.h"

namespace Hazel
{
	class NativeScriptPanel
	{
	public:
		void Draw(NativeScriptComponent &script)
		{
			ImGui::Text("Type: %s", script.GetTypeName());
			script.Script->OnGui();
		}
	};
}