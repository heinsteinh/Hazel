#pragma once

#include "Hazel/Core/Yaml/Vector4Serializer.h"
#include "Hazel/Core/Yaml/RectangleSerializer.h"
#include "Hazel/Scene/Components/SpriteComponent.h"

namespace Hazel
{
	template<>
	struct YamlSerializer<SpriteComponent>
	{
		static void Serialize(YamlDocument &document, const SpriteComponent &value)
		{
			auto &texture = value.Material.Texture.GetSource();
			auto &shader = value.Material.Shader;
			document.BeginMap()
				.Write("Color", value.Material.Color)
				.Write("TextureId", texture ? texture->GetName() : "")
				.Write("TextureFilename", texture ? texture->GetFilename() : "")
				.Write("TextureRegion", value.Material.Texture.GetRegion())
				.Write("ShaderId", shader ? shader->GetName() : "")
				.Write("ShaderFilename", shader ? shader->GetFilename() : "")
				.EndMap();
		}

		static void Deserialize(const YamlValue &source, SpriteComponent &value)
		{
			source["Color"].Extract(value.Material.Color);
		}

		static std::string GetTextureName(const YamlValue &source)
		{
			return source["TextureId"].ValueOr(std::string());
		}

		static std::string GetTextureFilename(const YamlValue &source)
		{
			return source["TextureFilename"].ValueOr(std::string());
		}

		static void UpdateTextureRegion(const YamlValue &source, SubTexture &texture)
		{
			texture.SetRegion(source["TextureRegion"].ValueOr(texture.GetRegion()));
		}

		static std::string GetShaderName(const YamlValue &source)
		{
			return source["ShaderId"].ValueOr(std::string());
		}

		static std::string GetShaderFilename(const YamlValue &source)
		{
			return source["ShaderFilename"].ValueOr(std::string());
		}
	};

	using SpriteSerializer = YamlSerializer<SpriteComponent>;
}