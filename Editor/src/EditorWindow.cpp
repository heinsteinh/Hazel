#include "EditorWindow.h"

#include "EditorDockSpaceFlags.h"

namespace Hazel
{
	void EditorWindow::Begin()
	{
		SetupFlags();
		SetupViewport();
		BeginWindow();
		ActivateDockSpace();
		menu.Draw();
	}

	void EditorWindow::End()
	{
		ImGui::End();
	}

	void EditorWindow::SetupFlags()
	{
		windowFlags = EditorDockSpaceFlags::GetWindowFlags(fullScreen, dockSpaceFlags);
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

	void EditorWindow::BeginWindow()
	{
		if (fullScreen)
		{
			ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
			ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
		}
		ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, {0.0f, 0.0f});
		ImGui::Begin("Hazel", nullptr, windowFlags);
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
			ImGui::DockSpace(ImGui::GetID("HazelDockSpace"), {0.0f, 0.0f}, dockSpaceFlags);
		}
	}
}