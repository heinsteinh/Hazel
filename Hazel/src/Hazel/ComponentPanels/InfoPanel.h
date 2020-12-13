#pragma once

#include "imgui.h"

#include "Hazel/Application/Layer.h"

namespace Hazel
{
	class InfoPanel
	{
	public:
		void Draw(const Layer &layer)
		{
			auto deltaTime = layer.GetDeltaTime();
			ImGui::Text("Update Time: %.2fms (%.2fFPS)", 1000 * deltaTime, 1.0f / deltaTime);
		}
	};
}