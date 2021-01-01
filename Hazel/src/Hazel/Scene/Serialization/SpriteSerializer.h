#pragma once

#include "Hazel/Scene/Components/SpriteComponent.h"
#include "Hazel/Core/Yaml/Vector4Serializer.h"
#include "Hazel/Core/Yaml/RectangleSerializer.h"

namespace Hazel
{
	template<>
	struct YamlSerializer<SpriteComponent>
	{
		static void Serialize(YamlDocument &document, const SpriteComponent &value)
		{
			document.BeginMap()
				.Write("Color", value.Color)
				.Write("TextureFilename", value.TextureFilename)
				.Write("TextureRegion", value.Texture.GetRegion())
				.EndMap();
		}

		static void Deserialize(const YamlValue &source, SpriteComponent &value)
		{
			source["Color"].Extract(value.Color);
			source["TextureFilename"].Extract(value.TextureFilename);
			value.Texture.SetRegion(source["TextureRegion"].ValueOr(value.Texture.GetRegion()));
		}
	};

	using SpriteSerializer = YamlSerializer<SpriteComponent>;
}