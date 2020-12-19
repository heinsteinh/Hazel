#pragma once

#include "imgui.h"

#include "Hazel/Scene/Components/SpriteComponent.h"

#include "Private/TexturePanel.h"

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
			if (sprite.Texture && ImGui::TreeNodeEx("Texture", ImGuiTreeNodeFlags_DefaultOpen))
			{
				texturePanel.Draw(sprite.Texture);
				ImGui::TreePop();
			}
		}
	};
}