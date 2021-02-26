#pragma once

#include "Hazel/Core/Input/Input.h"
#include "Hazel/Editor/Widgets/MenuBar.h"
#include "EditorMenuStatus.h"

namespace Hazel
{
	class EditorMenu
	{
	public:
		static EditorMenuStatus Draw(const Input &input)
		{
			EditorMenuStatus status;
			if (MenuBar::Begin())
			{
				if (MenuBar::BeginMenu("File"))
				{
					if (MenuBar::DrawItem("Open...", "Ctrl+O") || input.IsKeyPressed(Key::LeftControl, Key::O))
					{
						status.Open = true;
					}
					if (MenuBar::DrawItem("Save As...", "Ctrl+S") || input.IsKeyPressed(Key::LeftControl, Key::S))
					{
						status.Save = true;
					}
					if (MenuBar::DrawItem("Quit", "Ctrl+Q") || input.IsKeyPressed(Key::LeftControl, Key::Q))
					{
						status.Quit = true;
					}
					MenuBar::EndMenu();
				}
				MenuBar::End();
			}
			return status;
		}
	};
}