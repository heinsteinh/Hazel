#pragma once

#include "imgui.h"

#include "PopupSettings.h"
#include "Private/PopupFlags.h"

namespace Hazel
{
	class Popup
	{
	public:
		static void Open(const char *id)
		{
			ImGui::OpenPopup(id);
		}

		static bool Begin(const char *id = nullptr, const PopupSettings &settings = {})
		{
			return ImGui::BeginPopup(id, PopupFlags::GetFlags(settings));
		}

		static bool BeginOnItem(const char *id = nullptr, const PopupSettings &settings = {})
		{
			return ImGui::BeginPopupContextItem(id, PopupFlags::GetFlags(settings));
		}

		static bool BeginOnWindow(const char *id = nullptr, const PopupSettings &settings = {})
		{
			return ImGui::BeginPopupContextWindow(id, PopupFlags::GetFlags(settings));
		}

		static bool DrawItem(const char *label)
		{
			return ImGui::MenuItem(label);
		}

		static void Close()
		{
			ImGui::CloseCurrentPopup();
		}

		static void End()
		{
			ImGui::EndPopup();
		}
	};
}