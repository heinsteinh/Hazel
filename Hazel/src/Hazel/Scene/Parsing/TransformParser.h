#pragma once

#include "Hazel/Scene/Components/TransformComponent.h"
#include "Hazel/Core/Yaml/YamlParser.h"

namespace Hazel
{
	class TransformParser
	{
	public:
		static void Parse(const YamlValue &source, TransformComponent &component)
		{
			source["Translation"].Extract(component.Transform.Translation);
			source["EulerHint"].Extract(component.EulerHint);
			source["Scale"].Extract(component.Transform.Scale);
			component.RecomputeRotation();
		}

		static void Parse(const YamlValue &source, Transform &transform)
		{
			source["Translation"].Extract(transform.Translation);
			source["Rotation"].Extract(transform.Rotation);
			source["Scale"].Extract(transform.Scale);
		}
	};

	template<>
	void YamlParser::Parse(const YamlValue &source, TransformComponent &value)
	{
		return TransformParser::Parse(source, value);
	}

	template<>
	void YamlParser::Parse(const YamlValue &source, Transform &value)
	{
		return TransformParser::Parse(source, value);
	}
}