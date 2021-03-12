#pragma once

#include "Hazel/Editor/Widgets/Popup.h"

namespace Hazel
{
	class CreateEntityPopup
	{
	public:
		struct Status
		{
			bool EntityCreated = false;
		};

		static Status Draw()
		{
			Status status;
			PopupSettings settings;
			settings.MouseButton = MouseButton::Right;
			settings.OpenOverItem = false;
			if (Popup::BeginOnWindow(nullptr, settings))
			{
				if (Popup::DrawItem("Create Empty Entity"))
				{
					status.EntityCreated = true;
				}
				Popup::End();
			}
			return status;
		}
	};
}