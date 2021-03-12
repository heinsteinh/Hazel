#pragma once

#include "Hazel/Rendering/Textures/TextureFactory.h"
#include "Hazel/Scene/SceneManager/SceneManagerView.h"
#include "Hazel/Scene/Components/Sprite/SpriteSerializer.h"

namespace Hazel
{
	class TextureExtractor
	{
	private:
		AssetManager *assetManager;
		TextureFactory factory;

	public:
		TextureExtractor(SceneManagerView manager)
			: assetManager(&manager.GetAssetManager()),
			factory(manager.GetGraphicsContext())
		{
		}

		std::shared_ptr<Texture> ExtractTexture(const YamlValue &source)
		{
			return TryGetOrCreateTexture(ExtractTextureInfo(source));
		}

	private:
		TextureInfo ExtractTextureInfo(const YamlValue &source)
		{
			TextureInfo info;
			info.Filename = SpriteSerializer::GetTextureFilename(source);
			info.Name = SpriteSerializer::GetTextureName(source);
			return info;
		}

		std::shared_ptr<Texture> TryGetOrCreateTexture(TextureInfo &info)
		{
			auto texture = assetManager->GetTexture(info.Filename);
			if (texture)
			{
				return texture;
			}
			return factory.TryCreateTextureFromFile(info);
		}
	};
}