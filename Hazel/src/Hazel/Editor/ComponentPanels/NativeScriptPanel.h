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
			ImGui::Text("Script Id: %s", component.Script->GetName().c_str());
			component.Script->OnGui();
		}
	};
}