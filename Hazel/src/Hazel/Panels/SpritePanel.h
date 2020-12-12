#pragma once

#include "imgui.h"

#include "Hazel/Components/SpriteComponent.h"
#include "TexturePanel.h"

namespace Hazel
{
	class SpritePanel
	{
	private:
		TexturePanel texturePanel;

	public:
		void Draw(SpriteComponent &sprite)
		{
			ImGui::ColorEdit4("Color", glm::value_ptr(sprite.Color));
			texturePanel.Draw(sprite.Texture);
		}
	};
}