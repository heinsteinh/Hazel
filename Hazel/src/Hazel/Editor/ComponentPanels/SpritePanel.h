#pragma once

#include "imgui.h"

#include "Hazel/Scene/Components/SpriteComponent.h"
#include "Hazel/Editor/Widgets/InputText.h"
#include "Hazel/Editor/Widgets/RectanglePanel.h"
#include "Hazel/Editor/Utils/TreeNodeFlags.h"

namespace Hazel
{
	class SpritePanel
	{
	private:
		InputText inputText;
		RectanglePanel rectanglePanel;
		bool browse = false;
		bool load = false;

	public:
		void Draw(SpriteComponent &component)
		{
			browse = load = false;
			ImGui::ColorEdit4("Color", glm::value_ptr(component.Color));
			if (ImGui::TreeNodeEx("Texture", TreeNodeFlags::GetDefaultFlags()))
			{
				inputText.Draw("Path", component.TextureTemporaryFilename);
				browse = ImGui::Button("Browse");
				load = ImGui::Button("Load");
				if (component.Texture)
				{
					ImGui::Text("Region");
					auto region = component.Texture.GetRegion();
					if (rectanglePanel.Draw(region))
					{
						component.Texture.SetRegion(region);
					}
				}
				ImGui::TreePop();
			}
		}

		bool WantBrowse() const
		{
			return browse;
		}

		bool WantLoad() const
		{
			return load;
		}
	};
}