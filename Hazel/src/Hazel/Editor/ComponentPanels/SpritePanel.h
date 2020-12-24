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
		void Draw(SpriteComponent &component)
		{
			ImGui::ColorEdit4("Color", glm::value_ptr(component.Color));
			if (component.Texture && ImGui::TreeNodeEx("Texture", TreeNodeFlags::GetDefaultFlags()))
			{
				texturePanel.Draw(component.Texture);
				ImGui::TreePop();
			}
		}
	};
}