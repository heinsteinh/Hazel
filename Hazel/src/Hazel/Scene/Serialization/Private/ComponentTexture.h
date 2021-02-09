#pragma once

#include "Hazel/Core/Yaml/YamlSerializer.h"
#include "Hazel/Scene/Entity/Entity.h"
#include "Hazel/Scene/Serialization/SpriteSerializer.h"

namespace Hazel
{
	class ComponentTexture
	{
	public:
		static std::shared_ptr<Texture> ExtractTexture(const YamlValue &source, Entity entity)
		{
			auto name = SpriteSerializer::GetTextureName(source);
			if (name.empty())
			{
				return nullptr;
			}
			auto &assetManager = entity.GetAssetManager();
			auto texture = assetManager.GetTexture(name);
			if (texture)
			{
				return texture;
			}
			texture = CreateTexture(source, entity);
			return texture ? assetManager.AddTexture(texture) : nullptr;
		}

	private:
		static std::shared_ptr<Texture> CreateTexture(const YamlValue &source, Entity entity)
		{
			return TextureFactory::CreateTextureFromFile(
				entity.GetLayer().GetGraphicsContext(),
				SpriteSerializer::GetTextureFilename(source));
		}
	};
}