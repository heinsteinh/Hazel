#pragma once

#include "glm/glm.hpp"

#include "YamlSerializer.h"

namespace Hazel
{
	template<>
	struct YamlSerializer<glm::vec3>
	{
		static void Serialize(YamlDocument &document, const glm::vec3 &value)
		{
			document.InlineBlock()
				.BeginSequence()
				.Write(value.x)
				.Write(value.y)
				.Write(value.z)
				.EndSequence();
		}

		static void Deserialize(const YamlValue &source, glm::vec3 &value)
		{
			source[0].Extract(value.x);
			source[1].Extract(value.y);
			source[2].Extract(value.z);
		}
	};

	using Vector3Serializer = YamlSerializer<glm::vec3>;
}