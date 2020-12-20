#pragma once

#include "yaml-cpp/yaml.h"

#include "Hazel/Scene/Components/SpriteComponent.h"
#include "GeometrySerializer.h"

namespace Hazel
{
	class SpriteSerializer
	{
	public:
		static void Serialize(const SpriteComponent &sprite, YAML::Emitter &emitter)
		{
			emitter << YAML::BeginMap;
			emitter << YAML::Key << "Color" << YAML::Value << sprite.Color;
			emitter << YAML::EndMap;
		}
	};

	inline YAML::Emitter &operator<<(YAML::Emitter &emitter, const SpriteComponent &sprite)
	{
		SpriteSerializer::Serialize(sprite, emitter);
		return emitter;
	}
}