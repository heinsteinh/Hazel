#pragma once

#include "Hazel/Editor/Widgets/TextBox.h"

namespace Hazel
{
	class FpsPanel
	{
	public:
		static void Draw(float deltaTime)
		{
			float updateTime = 1000.0f * deltaTime;
			float fps = 1.0f / deltaTime;
			TextBox::Draw("Update Time: %.2fms (%.2fFPS)", updateTime, fps);
		}
	};
}