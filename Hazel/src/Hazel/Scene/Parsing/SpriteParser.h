#pragma once

#include "Hazel/Scene/Components/SpriteComponent.h"
#include "Hazel/Core/Yaml/YamlParser.h"

namespace Hazel
{
	class SpriteParser
	{
	public:
		static void Parse(const YamlValue &source, SpriteComponent &component)
		{
			source.Extract(component.Color);
		}
	};

	template<>
	void YamlParser::Parse(const YamlValue &source, SpriteComponent &value)
	{
		return SpriteParser::Parse(source, value);
	}
}