#pragma once

#include "imgui.h"

namespace Hazel
{
	class FpsPanel
	{
	public:
		void Draw(float deltaTime)
		{
			float updateTime = 1000.0f * deltaTime;
			float fps = 1.0f / deltaTime;
			ImGui::Text("Update Time: %.2fms (%.2fFPS)", updateTime, fps);
		}
	};
}