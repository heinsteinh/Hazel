#pragma once

#include "imgui.h"

#include "Hazel/Scene/Components/SpriteComponent.h"

#include "Hazel/Editor/Widgets/TexturePanel.h"
#include "Hazel/Editor/Utils/TreeNodeFlags.h"

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
			if (sprite.Texture && ImGui::TreeNodeEx("Texture", TreeNodeFlags::GetDefaultFlags()))
			{
				texturePanel.Draw(sprite.Texture);
				ImGui::TreePop();
			}
		}
	};
}