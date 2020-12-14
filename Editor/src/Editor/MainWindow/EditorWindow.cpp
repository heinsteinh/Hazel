#include "EditorWindow.h"

#include "EditorDockSpaceFlags.h"

namespace Hazel
{
	void EditorWindow::Begin(const char *label)
	{
		SetupViewport();
		PushWindowStyle();
		BeginWindow(label);
		PopWindowStyle();
		ActivateDockSpace();
		menu.Draw();
	}

	void EditorWindow::End()
	{
		ImGui::End();
	}

	void EditorWindow::SetupViewport()
	{
		if (fullScreen)
		{
			auto viewport = ImGui::GetMainViewport();
			ImGui::SetNextWindowPos(viewport->Pos);
			ImGui::SetNextWindowSize(viewport->Size);
			ImGui::SetNextWindowViewport(viewport->ID);
		}
	}

	void EditorWindow::PushWindowStyle()
	{
		if (fullScreen)
		{
			ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
			ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
		}
		ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, {0.0f, 0.0f});
	}

	void EditorWindow::BeginWindow(const char *label)
	{
		ImGui::Begin(label, nullptr, EditorDockSpaceFlags::GetWindowFlags(fullScreen, ImGuiDockNodeFlags_None));
	}

	void EditorWindow::PopWindowStyle()
	{
		ImGui::PopStyleVar();
		if (fullScreen)
		{
			ImGui::PopStyleVar(2);
		}
	}

	void EditorWindow::ActivateDockSpace()
	{
		if (ImGui::GetIO().ConfigFlags & ImGuiConfigFlags_DockingEnable)
		{
			ImGui::DockSpace(ImGui::GetID("HazelDockSpace"), {0.0f, 0.0f});
		}
	}
}