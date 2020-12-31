#pragma once

#include "imgui.h"

namespace Hazel
{
	class GuiStyle
	{
	public:
		static void SetDefaultStyle()
		{
			ImGui::StyleColorsDark();
			auto &style = ImGui::GetStyle();
			style.WindowRounding = 0.0f;
			style.Colors[ImGuiCol_WindowBg].w = 1.0f;
			auto &io = ImGui::GetIO();
			io.FontDefault = io.Fonts->AddFontFromFileTTF(
				"C:\\Users\\christian\\source\\repos\\Hazel\\Hazel\\assets\\fonts\\OpenSans\\OpenSans-Regular.ttf",
				18.0f);
			SetDarkThemeColors();
		}

		static void SetDarkThemeColors()
		{
			auto &colors = ImGui::GetStyle().Colors;
			colors[ImGuiCol_WindowBg] = {0.1f, 0.105f, 0.11f, 1.0f};
			colors[ImGuiCol_Header] = {0.2f, 0.205f, 0.21f, 1.0f};
			colors[ImGuiCol_HeaderHovered] = {0.3f, 0.305f, 0.31f, 1.0f};
			colors[ImGuiCol_HeaderActive] = {0.15f, 0.1505f, 0.151f, 1.0f};
			colors[ImGuiCol_Button] = {0.2f, 0.205f, 0.21f, 1.0f};
			colors[ImGuiCol_ButtonHovered] = {0.3f, 0.305f, 0.31f, 1.0f};
			colors[ImGuiCol_ButtonActive] = {0.15f, 0.1505f, 0.151f, 1.0f};
			colors[ImGuiCol_FrameBg] = {0.2f, 0.205f, 0.21f, 1.0f};
			colors[ImGuiCol_FrameBgHovered] = {0.3f, 0.305f, 0.31f, 1.0f};
			colors[ImGuiCol_FrameBgActive] = {0.15f, 0.1505f, 0.151f, 1.0f};
			colors[ImGuiCol_Tab] = {0.15f, 0.1505f, 0.151f, 1.0f};
			colors[ImGuiCol_TabHovered] = {0.38f, 0.3805f, 0.381f, 1.0f};
			colors[ImGuiCol_TabActive] = {0.28f, 0.2805f, 0.281f, 1.0f};
			colors[ImGuiCol_TabUnfocused] = {0.15f, 0.1505f, 0.151f, 1.0f};
			colors[ImGuiCol_TabUnfocusedActive] = {0.2f, 0.205f, 0.21f, 1.0f};
			colors[ImGuiCol_TitleBg] = {0.15f, 0.1505f, 0.151f, 1.0f};
			colors[ImGuiCol_TitleBgActive] = {0.15f, 0.1505f, 0.151f, 1.0f};
			colors[ImGuiCol_TitleBgCollapsed] = {0.15f, 0.1505f, 0.151f, 1.0f};
		}
	};
}