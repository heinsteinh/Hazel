#pragma once

#include <memory>

#include "Hazel/Rendering/Textures/Texture.h"
#include "Hazel/Editor/Widgets/Button.h"
#include "Hazel/Editor/Widgets/Spacer.h"
#include "Hazel/Editor/Widgets/TextBox.h"

namespace Hazel
{
	class TextureSourceWidget
	{
	public:
		struct Status
		{
			bool Changed = false;
			bool BrowseTexture = false;
			bool RemoveTexture = false;
		};

		static Status Draw(const std::shared_ptr<Texture> &texture)
		{
			Status status;
			TextBox::Draw("Source: %s", texture ? texture->GetName().c_str() : "None");
			if (texture && Button::Draw("Remove"))
			{
				status.RemoveTexture = true;
			}
			Spacer::Draw();
			if (Button::Draw("Browse..."))
			{
				status.BrowseTexture = true;
			}
			return status;
		}
	};
}