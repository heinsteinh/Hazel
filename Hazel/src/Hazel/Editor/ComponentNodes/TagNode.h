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
		static bool Draw(Entity entity, TagComponent &component)
		{
			return InputText::Draw("##Tag", component.Name);
		}
	};
}