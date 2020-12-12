#pragma once

#include "imgui.h"

#include "Hazel/Components/SpriteComponent.h"

namespace Hazel
{
	class SpritePanel
	{
	public:
		void Draw(SpriteComponent &sprite)
		{
			ImGui::ColorEdit4("Color", glm::value_ptr(sprite.Color));
		}
	};
}