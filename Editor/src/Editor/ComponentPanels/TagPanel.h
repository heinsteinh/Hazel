#pragma once

#include "imgui.h"

#include "Hazel/Components/TagComponent.h"

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

		void Draw(TagComponent &tag)
		{
			Draw("Tag", tag.Name);
		}

		void Draw(const char *label, std::string &tag)
		{
			buffer = tag;
			if (ImGui::InputText(label, buffer.data(), buffer.size() + 1))
			{
				tag = buffer;
			}
		}
	};
}