#pragma once

#include "Hazel/Core/FileSystem/FileDialog.h"
#include "Hazel/Scene/Entity/Entity.h"
#include "Hazel/Scene/Components/SpriteComponent.h"

namespace Hazel
{
	class TextureDialog
	{
	public:
		static void UpdateTextureFromFile(Entity entity, SpriteComponent &component)
		{
			auto &layer = entity.GetLayer();
			FileDialog dialog(layer.GetWindow());
			if (dialog.GetOpenFilename())
			{
				component.Material.Texture = CreateTextureFromFile(entity, dialog.GetFilename());
			}
		}

	private:
		static std::shared_ptr<Texture> CreateTextureFromFile(Entity entity, const std::string &filename)
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
	};
}