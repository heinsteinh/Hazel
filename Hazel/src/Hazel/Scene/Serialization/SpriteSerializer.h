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
			document.BeginMap()
				.Write("Color", value.Material.Color)
				.Write("Texture", texture ? texture->GetName() : "")
				.Write("TextureRegion", value.Material.Texture.GetRegion())
				.Write("Shader", value.Material.Shader->GetName())
				.EndMap();
		}

		static void Deserialize(const YamlValue &source, SpriteComponent &value)
		{
			source["Color"].Extract(value.Material.Color);
			value.Material.Texture.SetRegion(source["TextureRegion"].ValueOr(value.Material.Texture.GetRegion()));
		}

		static std::string GetTextureName(const YamlValue &source)
		{
			return source["Texture"].ValueOr(std::string());
		}

		static std::string GetShaderName(const YamlValue &source)
		{
			return source["Shader"].ValueOr(std::string());
		}
	};

	using SpriteSerializer = YamlSerializer<SpriteComponent>;
}