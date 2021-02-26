#pragma once

#include "Hazel/Scene/Scene/Scene.h"
#include "Hazel/Editor/Widgets/Popup.h"

namespace Hazel
{
	class CreateEntityPopup
	{
	public:
		static void Draw(Scene &scene)
		{
			PopupSettings settings;
			settings.MouseButton = MouseButton::Right;
			settings.OpenOverItem = false;
			if (Popup::BeginOnWindow(nullptr, settings))
			{
				if (Popup::DrawItem("Create Empty Entity"))
				{
					auto newEntity = scene.CreateEntity("New Entity");
				}
				Popup::End();
			}
		}
	};
}