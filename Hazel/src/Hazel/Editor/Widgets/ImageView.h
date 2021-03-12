#pragma once

#include "imgui.h"
#include "glm/glm.hpp"

namespace Hazel
{
	class ImageView
	{
	public:
		static void Draw(void *texture, const glm::vec2 &viewport)
		{
			ImGui::Image(
				texture,
				{viewport.x, viewport.y},
				{0.0f, 1.0f},
				{1.0f, 0.0f});
		}
	};
}