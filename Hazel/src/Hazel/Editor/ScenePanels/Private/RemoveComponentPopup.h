#pragma once

#include "Hazel/Editor/Widgets/Popup.h"

namespace Hazel
{
	class RemoveComponentPopup
	{
	private:
		static constexpr const char *id = "RemoveComponent";

	public:
		struct Status
		{
			bool ComponentRemoved = false;
		};

		static void Open()
		{
			Popup::Open(id);
		}

		static Status Draw()
		{
			Status status;
			if (Popup::Begin(id))
			{
				if (Popup::DrawItem("Remove Component"))
				{
					status.ComponentRemoved = true;
				}
				Popup::End();
			}
			return status;
		}
	};
}