#pragma once

#include "imgui.h"

#include "Hazel/Core/FileSystem/FileDialog.h"
#include "Hazel/Rendering/Textures/TextureFactory.h"
#include "Hazel/Scene/Entity/Entity.h"
#include "Hazel/Scene/Components/SpriteComponent.h"
#include "Hazel/Editor/Widgets/TreeNode.h"
#include "Hazel/Editor/Widgets/InputColor.h"
#include "Hazel/Editor/Widgets/TextBox.h"
#include "Hazel/Editor/Widgets/Spacer.h"
#include "Hazel/Editor/Widgets/CheckBox.h"
#include "Hazel/Editor/Widgets/Button.h"
#include "Hazel/Editor/Utils/Box2DPanel.h"
#include "Private/TextureDialog.h"

namespace Hazel
{
	class SpriteNode
	{
	public:
		static bool Draw(Entity entity, SpriteComponent &component)
		{
			InputColor::Draw("Color", component.Material.Color);
			TreeNodeSettings settings;
			settings.DefaultOpen = true;
			settings.Framed = true;
			if (TreeNode::Begin("Texture", nullptr, settings))
			{
				DrawTextureSource(entity, component);
				DrawTextureRegion(component);
				TreeNode::End();
			}
			CheckBox::Draw("Transparency", component.Material.Transparency);
			return false;
		}

	private:
		static void DrawTextureSource(Entity entity, SpriteComponent &component)
		{
			auto &texture = component.Material.Texture.GetSource();
			TextBox::Draw("Source: %s", texture ? texture->GetName().c_str() : "None");
			if (Button::Draw("Remove"))
			{
				component.Material.Texture.SetSource(nullptr);
			}
			Spacer::Draw();
			if (Button::Draw("Browse..."))
			{
				TextureDialog::UpdateTextureFromFile(entity, component);
			}
		}

		static void DrawTextureRegion(SpriteComponent &component)
		{
			if (component.Material.Texture)
			{
				TextBox::Draw("Region");
				auto region = component.Material.Texture.GetRegion();
				if (Box2DPanel::Draw(region))
				{
					component.Material.Texture.SetRegion(region);
				}
			}
		}
	};
}