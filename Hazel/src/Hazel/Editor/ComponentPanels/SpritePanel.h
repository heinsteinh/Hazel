#pragma once

#include "imgui.h"

#include "Hazel/Scene/Entity/Entity.h"
#include "Hazel/Scene/Components/SpriteComponent.h"
#include "Hazel/Core/FileSystem/FileDialog.h"
#include "Hazel/Editor/Widgets/RectanglePanel.h"
#include "Hazel/Editor/Utils/TreeNodeFlags.h"

namespace Hazel
{
	class SpritePanel
	{
	private:
		RectanglePanel rectanglePanel;

	public:
		void Draw(Entity entity, SpriteComponent &component)
		{
			ImGui::ColorEdit4("Color", glm::value_ptr(component.Color));
			if (ImGui::TreeNodeEx("Texture", TreeNodeFlags::GetDefaultFlags()))
			{
				ImGui::Text("Source: %s", component.TextureFilename.c_str());
				if (ImGui::Button("Remove"))
				{
					component.TextureFilename.clear();
					component.Texture.SetSource(nullptr);
				}
				ImGui::SameLine();
				if (ImGui::Button("Browse..."))
				{
					FileDialog dialog(entity.GetLayer().GetWindow());
					if (dialog.GetOpenFilename())
					{
						component.TextureFilename = dialog.GetFilename();
						component.Texture = entity.GetTextureManager().Load(component.TextureFilename);
					}
				}
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
	};
}