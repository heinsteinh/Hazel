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
			ImGui::Checkbox("Transparency", &component.Material.Transparency);
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
				UpdateTextureFromFile(entity, component);
			}
		}

		void UpdateTextureFromFile(Entity entity, SpriteComponent &component)
		{
			auto &layer = entity.GetLayer();
			FileDialog dialog(layer.GetWindow());
			if (dialog.GetOpenFilename())
			{
				component.Material.Texture = CreateTextureFromFile(entity, dialog.GetFilename());
			}
		}

		std::shared_ptr<Texture> CreateTextureFromFile(Entity entity, const std::string &filename)
		{
			auto &assetManager = entity.GetAssetManager();
			auto texture = assetManager.GetTexture(filename);
			if (texture)
			{
				return texture;
			}
			return assetManager.AddTexture(TextureFactory::CreateTextureFromFile(
				entity.GetLayer().GetGraphicsContext(),
				filename));
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