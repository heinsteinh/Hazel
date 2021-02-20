#pragma once

#include "Hazel/Core/Yaml/YamlSerializer.h"
#include "Hazel/Core/Images/Image.h"
#include "Hazel/Scene/Entity/Entity.h"
#include "Hazel/Scene/Serialization/SpriteSerializer.h"

namespace Hazel
{
	class ComponentTexture
	{
	public:
		static std::shared_ptr<Texture> ExtractTexture(const YamlValue &source, Entity entity)
		{
			auto filename = SpriteSerializer::GetTextureFilename(source);
			if (filename.empty())
			{
				return nullptr;
			}
			auto &assetManager = entity.GetAssetManager();
			auto texture = assetManager.GetTexture(filename);
			if (texture)
			{
				return texture;
			}
			texture = CreateTexture(source, entity, filename);
			return texture ? assetManager.AddTexture(texture) : nullptr;
		}

	private:
		static std::shared_ptr<Texture> CreateTexture(const YamlValue &source, Entity entity, const std::string &filename)
		{
			auto image = Image::FromFile(filename);
			if (!image.IsValid())
			{
				return nullptr;
			}
			TextureInfo info;
			info.Name = SpriteSerializer::GetTextureName(source);
			if (info.Name.empty())
			{
				info.Name = Filename::GetBaseName(filename);
			}
			info.Filename = filename;
			info.Size = image.GetSize();
			info.Data = image.GetData();
			auto texture = entity.GetLayer().GetGraphicsContext().CreateTexture(info);
			return texture;
		}
	};
}