#pragma once

#include "Hazel/Scene/Components/TagComponent.h"
#include "Hazel/Core/Yaml/YamlSerializer.h"

namespace Hazel
{
	template<>
	struct YamlSerializer<TagComponent>
	{
		static void Serialize(YamlDocument &document, const TagComponent &value)
		{
			document.BeginMap()
				.Write("Name", value.Name)
				.EndMap();
		}

		static void Deserialize(const YamlValue &source, TagComponent &value)
		{
			source["Name"].Extract(value.Name);
		}
	};

	using TagSerializer = YamlSerializer<TagComponent>;
}