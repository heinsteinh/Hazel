#pragma once

#include "Hazel/Scene/Components/SpriteComponent.h"
#include "Hazel/Core/Yaml/YamlSerializer.h"

namespace Hazel
{
	class SpriteSerializer
	{
	public:
		static void Serialize(YamlDocument &document, const SpriteComponent &component)
		{
			document.BeginMap()
				.Key().Write("Color").Value().Write(component.Color)
				.EndMap();
		}
	};

	template<>
	inline void YamlSerializer::Serialize(YamlDocument &document, const SpriteComponent &value)
	{
		return SpriteSerializer::Serialize(document, value);
	}
}