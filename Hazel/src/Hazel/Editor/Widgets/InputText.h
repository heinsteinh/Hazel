#pragma once

#include <string>

#include "imgui.h"

namespace Hazel
{
	class InputText
	{
	private:
		std::string buffer;

	public:
		InputText(size_t size = 128)
			: buffer(512, '\0')
		{
		}

		void Draw(const char *label, std::string &value)
		{
			buffer = value;
			if (ImGui::InputText(label, buffer.data(), buffer.capacity()))
			{
				value = buffer;
			}
		}
	};
}