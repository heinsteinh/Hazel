#pragma once

#include <string>

#include "imgui.h"

namespace Hazel
{
	class InputText
	{
	public:
		static bool Draw(const char *label, std::string &value)
		{
			return ImGui::InputText(
				label,
				value.data(),
				value.capacity() + 1,
				ImGuiInputTextFlags_CallbackResize,
				&ResizeCallback,
				&value);
		}

	private:
		static int ResizeCallback(ImGuiInputTextCallbackData *data)
		{
			auto value = static_cast<std::string *>(data->UserData);
			if (data->EventFlag == ImGuiInputTextFlags_CallbackResize)
			{
				value->resize(data->BufTextLen);
				data->Buf = value->data();
			}
			return 0;
		}
	};
}