#pragma once

#include "imgui.h"

#include "Hazel/Scene/Entity/Entity.h"
#include "Hazel/Scene/Components/NativeScriptComponent.h"

namespace Hazel
{
	class NativeScriptPanel
	{
	public:
		void Draw(Entity entity, NativeScriptComponent &component)
		{
			ImGui::Text("Type: %s", component.GetTypeName());
			component.Script->OnGui();
		}
	};
}