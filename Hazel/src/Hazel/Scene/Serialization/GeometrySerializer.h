#pragma once

#include "glm/glm.hpp"
#include "yaml-cpp/yaml.h"

namespace Hazel
{
	class GeometrySerializer
	{
	public:
		static void Serialize(const glm::vec2 &value, YAML::Emitter &emitter)
		{
			emitter << YAML::Flow;
			emitter << YAML::BeginSeq << value.x << value.y << YAML::EndSeq;
		}

		static void Serialize(const glm::vec3 &value, YAML::Emitter &emitter)
		{
			emitter << YAML::Flow;
			emitter << YAML::BeginSeq << value.x << value.y << value.z << YAML::EndSeq;
		}

		static void Serialize(const glm::vec4 &value, YAML::Emitter &emitter)
		{
			emitter << YAML::Flow;
			emitter << YAML::BeginSeq << value.x << value.y << value.z << value.w << YAML::EndSeq;
		}

		static void Serialize(const glm::quat &value, YAML::Emitter &emitter)
		{
			emitter << YAML::Flow;
			emitter << YAML::BeginSeq << value.x << value.y << value.z << value.w << YAML::EndSeq;
		}
	};

	inline YAML::Emitter &operator<<(YAML::Emitter &emitter, const glm::vec2 &value)
	{
		GeometrySerializer::Serialize(value, emitter);
		return emitter;
	}

	inline YAML::Emitter &operator<<(YAML::Emitter &emitter, const glm::vec3 &value)
	{
		GeometrySerializer::Serialize(value, emitter);
		return emitter;
	}

	inline YAML::Emitter &operator<<(YAML::Emitter &emitter, const glm::vec4 &value)
	{
		GeometrySerializer::Serialize(value, emitter);
		return emitter;
	}

	inline YAML::Emitter &operator<<(YAML::Emitter &emitter, const glm::quat &value)
	{
		GeometrySerializer::Serialize(value, emitter);
		return emitter;
	}
}