#pragma once

#include "imgui.h"

namespace Hazel
{
	class TextBox
	{
	public:
		template<typename ...Args>
		static void Draw(const char *format, Args &&...args)
		{
			ImGui::Text(format, std::forward<Args>(args)...);
		}

		static void Draw(const char *text)
		{
			ImGui::TextUnformatted(text);
		}
	};
}