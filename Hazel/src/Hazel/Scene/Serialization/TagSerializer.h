#pragma once

#include "Hazel/Scene/Components/TagComponent.h"
#include "Hazel/Core/Yaml/YamlSerializer.h"

namespace Hazel
{
	class TagSerializer
	{
	public:
		static void Serialize(YamlDocument &document, const TagComponent &component)
		{
			document.BeginMap()
				.Key().Write("Name").Value().Write(component.Name)
				.EndMap();
		}
	};

	template<>
	inline void YamlSerializer::Serialize(YamlDocument &document, const TagComponent &value)
	{
		return TagSerializer::Serialize(document, value);
	}
}