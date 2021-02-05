#pragma once

#include "imgui.h"

#include "Hazel/Core/FileSystem/FileDialog.h"
#include "Hazel/Rendering/Textures/TextureFactory.h"
#include "Hazel/Scene/Entity/Entity.h"
#include "Hazel/Scene/Components/SpriteComponent.h"
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
			ImGui::ColorEdit4("Color", glm::value_ptr(component.Material.Color));
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
			auto &texture = component.Material.Texture.GetSource();
			ImGui::Text("Source: %s", texture ? texture->GetName().c_str() : "None");
			if (ImGui::Button("Remove"))
			{
				component.Material.Texture.SetSource(nullptr);
			}
			ImGui::SameLine();
			if (ImGui::Button("Browse..."))
			{
				FileDialog dialog(entity.GetLayer().GetWindow());
				if (dialog.GetOpenFilename())
				{
					auto &filename = dialog.GetFilename();
					auto name = Filename::GetBaseName(filename);
					auto &assetManager = entity.GetAssetManager();
					component.Material.Texture = assetManager.GetTexture(name);
					if (!component.Material.Texture)
					{
						component.Material.Texture = assetManager.AddTexture(TextureFactory::CreateTextureFromFile(
							entity.GetLayer().GetGraphicsContext(),
							dialog.GetFilename()));
					}
				}
			}
		}

		void DrawTextureRegion(SpriteComponent &component)
		{
			if (component.Material.Texture)
			{
				ImGui::Text("Region");
				auto region = component.Material.Texture.GetRegion();
				if (rectanglePanel.Draw(region))
				{
					component.Material.Texture.SetRegion(region);
				}
			}
		}
	};
}