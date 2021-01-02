#pragma once

#include "imgui.h"

#include "Hazel/Scene/Components/TagComponent.h"
#include "Hazel/Editor/Widgets/InputText.h"

namespace Hazel
{
	class TagPanel
	{
	private:
		InputText input;

	public:
		void Draw(TagComponent &component)
		{
			input.Draw("##Tag", component.Name);
		}
	};
}