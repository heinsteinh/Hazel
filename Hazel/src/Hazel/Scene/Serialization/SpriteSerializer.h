#pragma once

#include "Hazel/Scene/Components/SpriteComponent.h"
#include "Hazel/Core/Yaml/Vector4Serializer.h"

namespace Hazel
{
	template<>
	struct YamlSerializer<SpriteComponent>
	{
		static void Serialize(YamlDocument &document, const SpriteComponent &value)
		{
			document.BeginMap()
				.Write("Color", value.Color)
				.EndMap();
		}

		static void Deserialize(const YamlValue &source, SpriteComponent &value)
		{
			source["Color"].Extract(value.Color);
		}
	};

	using SpriteSerializer = YamlSerializer<SpriteComponent>;
}