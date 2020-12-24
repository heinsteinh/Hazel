#pragma once

#include "Hazel/Scene/Components/TagComponent.h"
#include "Hazel/Core/Yaml/YamlParser.h"

namespace Hazel
{
	class TagParser
	{
	public:
		static void Parse(const YamlValue &source, TagComponent &tag)
		{
			source.Extract(tag.Name);
		}
	};

	template<>
	void YamlParser::Parse(const YamlValue &source, TagComponent &value)
	{
		return TagParser::Parse(source, value);
	}
}