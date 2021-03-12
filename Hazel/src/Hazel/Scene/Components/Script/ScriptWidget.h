#pragma once

#include "Hazel/Scene/Assets/Script.h"
#include "Hazel/Editor/Widgets/TextBox.h"

namespace Hazel
{
	class ScriptWidget
	{
	public:
		static bool Draw(Script &script)
		{
			TextBox::Draw("Script Name: %s", script.GetName().c_str());
			script.OnGui();
			return false;
		}
	};
}