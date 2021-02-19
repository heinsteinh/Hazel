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
				.Write("TextureName", texture ? texture->GetName() : "")
				.Write("TextureFilename", texture ? texture->GetFilename() : "")
				.Write("TextureRegion", value.Material.Texture.GetRegion())
				.Write("ShaderName", shader ? shader->GetName() : "")
				.Write("ShaderFilename", shader ? shader->GetFilename() : "")
				.Write("Transparency", value.Material.Transparency)
				.EndMap();
		}

		static void Deserialize(const YamlValue &source, SpriteComponent &value)
		{
			source["Color"].Extract(value.Material.Color);
			source["Transparency"].Extract(value.Material.Transparency);
		}

		static std::string GetTextureName(const YamlValue &source)
		{
			return source["TextureName"].GetValueOr(std::string());
		}

		static std::string GetTextureFilename(const YamlValue &source)
		{
			return source["TextureFilename"].GetValueOr(std::string());
		}

		static void UpdateTextureRegion(const YamlValue &source, SubTexture &texture)
		{
			texture.SetRegion(source["TextureRegion"].GetValueOr(texture.GetRegion()));
		}

		static std::string GetShaderName(const YamlValue &source)
		{
			return source["ShaderName"].GetValueOr(std::string());
		}

		static std::string GetShaderFilename(const YamlValue &source)
		{
			return source["ShaderFilename"].GetValueOr(std::string());
		}
	};

	using SpriteSerializer = YamlSerializer<SpriteComponent>;
}