#pragma once

#include "imgui.h"

#include "Hazel/Scene/Components/TagComponent.h"

namespace Hazel
{
	class TagPanel
	{
	private:
		std::string buffer;

	public:
		TagPanel(size_t bufferSize = 512)
			: buffer(bufferSize, '\0')
		{
		}

		void Draw(TagComponent &component)
		{
			Draw("##Tag", component.Name);
		}

		void Draw(const char *label, std::string &tag)
		{
			buffer = tag;
			if (ImGui::InputText(label, buffer.data(), buffer.capacity()))
			{
				tag = buffer;
			}
		}
	};
}