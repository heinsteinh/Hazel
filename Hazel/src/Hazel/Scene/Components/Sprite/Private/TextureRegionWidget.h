#pragma once

#include "Hazel/Rendering/Textures/SubTexture.h"
#include "Hazel/Editor/Widgets/TextBox.h"
#include "Hazel/Editor/Utils/Box2DPanel.h"

namespace Hazel
{
	class TextureRegionWidget
	{
	public:
		static bool Draw(SubTexture &texture)
		{
			if (!texture)
			{
				return false;
			}
			TextBox::Draw("Region");
			auto region = texture.GetRegion();
			if (Box2DPanel::Draw(region))
			{
				texture.SetRegion(region);
				return true;
			}
			return false;
		}
	};
}