#pragma once

#include "Hazel/Rendering/Textures/TextureFactory.h"
#include "Hazel/Scene/Scene/Entity.h"
#include "Hazel/Editor/Widgets/CheckBox.h"
#include "Hazel/Editor/Widgets/InputColor.h"
#include "Hazel/Editor/Widgets/TreeNode.h"
#include "SpriteComponent.h"
#include "Private/TextureRegionWidget.h"
#include "Private/TextureSourceWidget.h"

namespace Hazel
{
	class SpriteWidget
	{
	public:
		using Status = TextureSourceWidget::Status;

		static Status Draw(SpriteComponent &component)
		{
			return Draw(component.Material);
		}

		static Status Draw(Material &material)
		{
			Status status;
			auto colorChanged = InputColor::Draw("Color", material.Color);
			if (BeginTextureNode())
			{
				status = DrawTexture(material.Texture);
				TreeNode::End();
			}
			status.Changed |= colorChanged;
			status.Changed |= CheckBox::Draw("Transparency", material.Transparency);
			return status;
		}

	private:
		static bool BeginTextureNode()
		{
			TreeNodeSettings settings;
			settings.DefaultOpen = true;
			settings.Framed = true;
			return TreeNode::Begin("Texture", nullptr, settings);
		}

		static Status DrawTexture(SubTexture &texture)
		{
			auto status = TextureSourceWidget::Draw(texture);
			status.Changed |= TextureRegionWidget::Draw(texture);
			return status;
		}
	};
}