#pragma once

#include "Hazel/Utils/Size.h"

namespace Hazel
{
	class ImGuiRenderer
	{
	public:
		ImGuiRenderer() = default;

		void Begin();
		void End();
		void SetDisplaySize(Size size);

	private:
		void UpdateWindows();
	};
}