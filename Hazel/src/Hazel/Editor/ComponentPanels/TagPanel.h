#pragma once

#include "imgui.h"

#include "Hazel/Scene/Entity/Entity.h"
#include "Hazel/Scene/Components/TagComponent.h"
#include "Hazel/Editor/Widgets/InputText.h"

namespace Hazel
{
	class TagPanel
	{
	private:
		InputText input;

	public:
		void Draw(Entity entity, TagComponent &component)
		{
			input.Draw("##Tag", component.Name);
		}
	};
}