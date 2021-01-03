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
				DrawTextureSource(entity, component);
				DrawTextureRegion(component);
				ImGui::TreePop();
			}
		}

	private:
		void DrawTextureSource(Entity entity, SpriteComponent &component)
		{
			ImGui::Text("Source: %s", component.TextureFilename.empty() ? "None" : component.TextureFilename.c_str());
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
		}

		void DrawTextureRegion(SpriteComponent &component)
		{
			if (component.Texture)
			{
				ImGui::Text("Region");
				auto region = component.Texture.GetRegion();
				if (rectanglePanel.Draw(region))
				{
					component.Texture.SetRegion(region);
				}
			}
		}
	};
}