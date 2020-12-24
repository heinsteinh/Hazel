#pragma once

#include "Hazel/Scene/Components/NativeScriptComponent.h"
#include "Hazel/Core/Yaml/YamlParser.h"

namespace Hazel
{
	class NativeScriptParser
	{
	public:
		static void Parse(const YamlValue &source, NativeScriptComponent &component)
		{
		}
	};

	template<>
	void YamlParser::Parse(const YamlValue &source, NativeScriptComponent &value)
	{
		return NativeScriptParser::Parse(source, value);
	}
}