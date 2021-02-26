#pragma once

#include <cstdint>

#include "imgui.h"

#include "InputIntSettings.h"

namespace Hazel
{
	class InputInt
	{
	public:
		static bool Draw(const char *label, int &value, const InputIntSettings &settings = {})
		{
			return ImGui::DragInt(label, &value, settings.Speed, settings.Min, settings.Max, settings.Format);
		}

		template<typename T>
		static bool Draw(const char *label, T &value, const InputIntSettings &settings = {})
		{
			auto temp = static_cast<int>(value);
			auto changed = Draw(label, temp, settings);
			value = static_cast<T>(value);
			return value;
		}
	};
}