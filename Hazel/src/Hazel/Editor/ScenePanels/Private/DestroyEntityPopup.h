#pragma once

#include "Hazel/Editor/Widgets/Popup.h"

namespace Hazel
{
	class DestroyEntityPopup
	{
	public:
		struct Status
		{
			bool EntityDestroyed = false;
		};

		static Status Draw()
		{
			Status status;
			if (Popup::BeginOnItem())
			{
				if (Popup::DrawItem("Destroy Entity"))
				{
					status.EntityDestroyed = true;
				}
				Popup::End();
			}
			return status;
		}
	};
}