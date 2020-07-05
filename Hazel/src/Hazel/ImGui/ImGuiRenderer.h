#pragma once

#include "Hazel/Geometry/Size.h"

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