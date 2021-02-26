#pragma once

#include "imgui.h"

#include "Hazel/Scene/Entity/Entity.h"
#include "Hazel/Scene/Components/TagComponent.h"
#include "Hazel/Editor/Widgets/InputText.h"

namespace Hazel
{
	class TagNode
	{
	public:
		static bool Draw(TagComponent &component)
		{
			return Draw(component.Name);
		}

		static bool Draw(std::string &tag)
		{
			return InputText::Draw("##Tag", tag);
		}
	};
}