#pragma once

#include "imgui.h"

#include "Private/EditorWindowFlags.h"

namespace Hazel
{
	class EditorWindow
	{
	public:
		static void Begin(const char *label, bool fullScreen = true)
		{
			SetupViewport(fullScreen);
			PushWindowStyle(fullScreen);
			BeginWindow(label, fullScreen);
			PopWindowStyle(fullScreen);
			ActivateDockSpace();
		}

		static void End()
		{
			ImGui::End();
		}

	private:
		static void SetupViewport(bool fullScreen)
		{
			if (fullScreen)
			{
				auto viewport = ImGui::GetMainViewport();
				ImGui::SetNextWindowPos(viewport->Pos);
				ImGui::SetNextWindowSize(viewport->Size);
				ImGui::SetNextWindowViewport(viewport->ID);
			}
		}

		static void PushWindowStyle(bool fullScreen)
		{
			if (fullScreen)
			{
				ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
				ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
			}
			ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, {0.0f, 0.0f});
		}

		static void BeginWindow(const char *label, bool fullScreen)
		{
			ImGui::Begin(label, nullptr, EditorWindowFlags::GetWindowFlags(fullScreen, ImGuiDockNodeFlags_None));
		}

		static void PopWindowStyle(bool fullScreen)
		{
			ImGui::PopStyleVar();
			if (fullScreen)
			{
				ImGui::PopStyleVar(2);
			}
		}

		static void ActivateDockSpace()
		{
			if (ImGui::GetIO().ConfigFlags & ImGuiConfigFlags_DockingEnable)
			{
				ImGui::DockSpace(ImGui::GetID("HazelDockSpace"), {0.0f, 0.0f});
			}
		}
	};
}