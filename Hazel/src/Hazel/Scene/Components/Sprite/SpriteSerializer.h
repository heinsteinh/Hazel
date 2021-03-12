#pragma once

#include "Hazel/Core/Yaml/Vector4Serializer.h"
#include "Hazel/Core/Yaml/Box2DSerializer.h"
#include "SpriteComponent.h"

namespace Hazel
{
	template<>
	struct YamlSerializer<SpriteComponent>
	{
		static void Serialize(YamlDocument &yaml, const SpriteComponent &sprite)
		{
			auto &texture = sprite.Material.Texture.GetSource();
			auto &shader = sprite.Material.Shader;
			yaml.BeginMap()
				.Write("Color", sprite.Material.Color)
				.Write("TextureName", texture ? texture->GetName() : "")
				.Write("TextureFilename", texture ? texture->GetFilename() : "")
				.Write("TextureRegion", sprite.Material.Texture.GetRegion())
				.Write("ShaderName", shader ? shader->GetName() : "")
				.Write("ShaderFilename", shader ? shader->GetFilename() : "")
				.Write("Transparency", sprite.Material.Transparency)
				.EndMap();
		}

		static void Deserialize(const YamlValue &yaml, SpriteComponent &sprite)
		{
			yaml["Color"].Extract(sprite.Material.Color);
			yaml["Transparency"].Extract(sprite.Material.Transparency);
		}

		static std::string GetTextureName(const YamlValue &yaml)
		{
			return yaml["TextureName"].GetValueOr(std::string());
		}

		static std::string GetTextureFilename(const YamlValue &yaml)
		{
			return yaml["TextureFilename"].GetValueOr(std::string());
		}

		static void UpdateTextureRegion(const YamlValue &yaml, SubTexture &texture)
		{
			texture.SetRegion(yaml["TextureRegion"].GetValueOr(texture.GetRegion()));
		}

		static std::string GetShaderName(const YamlValue &yaml)
		{
			return yaml["ShaderName"].GetValueOr(std::string());
		}

		static std::string GetShaderFilename(const YamlValue &yaml)
		{
			return yaml["ShaderFilename"].GetValueOr(std::string());
		}
	};

	using SpriteSerializer = YamlSerializer<SpriteComponent>;
}