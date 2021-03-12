#pragma once

#include "glm/glm.hpp"

#include "YamlSerializer.h"

namespace Hazel
{
	template<>
	struct YamlSerializer<glm::vec3>
	{
		static void Serialize(YamlDocument &yaml, const glm::vec3 &v)
		{
			yaml.InlineBlock()
				.BeginSequence()
				.Write(v.x)
				.Write(v.y)
				.Write(v.z)
				.EndSequence();
		}

		static void Deserialize(const YamlValue &yaml, glm::vec3 &v)
		{
			yaml[0].Extract(v.x);
			yaml[1].Extract(v.y);
			yaml[2].Extract(v.z);
		}
	};

	using Vector3Serializer = YamlSerializer<glm::vec3>;
}