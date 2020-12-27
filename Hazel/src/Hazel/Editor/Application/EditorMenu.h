#pragma once

#include "imgui.h"

namespace Hazel
{
	class EditorMenu
	{
	private:
		bool quit = false;
		bool save = false;
		bool open = false;

	public:
		void Draw()
		{
			quit = save = open = false;
			if (ImGui::BeginMenuBar())
			{
				if (ImGui::BeginMenu("File"))
				{
					if (ImGui::MenuItem("Open...", "Ctrl+O"))
					{
						open = true;
					}
					if (ImGui::MenuItem("Save As...", "Ctrl+S"))
					{
						save = true;
					}
					if (ImGui::MenuItem("Quit", "Ctrl+Q"))
					{
						quit = true;
					}
					ImGui::EndMenu();
				}
				ImGui::EndMenuBar();
			}
		}

		bool WantQuit() const
		{
			return quit;
		}

		bool WantOpen() const
		{
			return open;
		}

		bool WantSave() const
		{
			return save;
		}
	};
}