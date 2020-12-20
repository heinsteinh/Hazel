#pragma once

#include "yaml-cpp/yaml.h"

#include "Hazel/Scene/Components/TransformComponent.h"
#include "GeometrySerializer.h"

namespace Hazel
{
	class TransformSerializer
	{
	public:
		static void Serialize(const TransformComponent &transform, YAML::Emitter &emitter)
		{
			Serialize(transform.Transform, emitter);
		}

		static void Serialize(const Transform &transform, YAML::Emitter &emitter)
		{
			emitter << YAML::BeginMap;
			emitter << YAML::Key << "Translation" << YAML::Value << transform.Translation;
			emitter << YAML::Key << "Rotation" << YAML::Value << transform.Rotation;
			emitter << YAML::Key << "Scale" << YAML::Value << transform.Scale;
			emitter << YAML::EndMap;
		}
	};

	inline YAML::Emitter &operator<<(YAML::Emitter &emitter, const TransformComponent &transform)
	{
		TransformSerializer::Serialize(transform, emitter);
		return emitter;
	}

	inline YAML::Emitter &operator<<(YAML::Emitter &emitter, const Transform &transform)
	{
		TransformSerializer::Serialize(transform, emitter);
		return emitter;
	}
}