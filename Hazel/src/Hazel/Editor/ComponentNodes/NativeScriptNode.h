#pragma once

#include "imgui.h"

#include "Hazel/Scene/Entity/Entity.h"
#include "Hazel/Scene/Components/NativeScriptComponent.h"
#include "Hazel/Editor/Widgets/TextBox.h"

namespace Hazel
{
	class NativeScriptNode
	{
	public:
		static bool Draw(Entity entity, NativeScriptComponent &component)
		{
			TextBox::Draw("Script Id: %s", component.Script->GetName().c_str());
			component.Script->OnGui();
			return false;
		}
	};
}