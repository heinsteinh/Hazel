#pragma once

namespace Hazel
{
	class EditorMenu
	{
	private:
		bool quit = false;

	public:
		bool WantQuit() const
		{
			return quit;
		}

		void Draw()
		{
			if (ImGui::BeginMenuBar())
			{
				if (ImGui::BeginMenu("File"))
				{
					if (ImGui::MenuItem("Quit", "Ctrl+Q"))
					{
						quit = true;
					}
					ImGui::EndMenu();
				}
				ImGui::EndMenuBar();
			}
		}
	};
}