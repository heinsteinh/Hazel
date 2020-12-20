#pragma once

#include "yaml-cpp/yaml.h"

#include "Hazel/Scene/Components/TagComponent.h"

namespace Hazel
{
	class TagSerializer
	{
	public:
		static void Serialize(const TagComponent &tag, YAML::Emitter &emitter)
		{
			emitter << YAML::BeginMap;
			emitter << YAML::Key << "Name" << YAML::Value << tag.Name;
			emitter << YAML::EndMap;
		}
	};

	inline YAML::Emitter &operator<<(YAML::Emitter &emitter, const TagComponent &tag)
	{
		TagSerializer::Serialize(tag, emitter);
		return emitter;
	}
}