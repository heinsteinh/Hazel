#pragma once

#include "glm/glm.hpp"

#include "YamlSerializer.h"

namespace Hazel
{
	template<>
	struct YamlSerializer<glm::vec2>
	{
		static void Serialize(YamlDocument &yaml, const glm::vec2 &v)
		{
			yaml.InlineBlock()
				.BeginSequence()
				.Write(v.x)
				.Write(v.y)
				.EndSequence();
		}

		static void Deserialize(const YamlValue &yaml, glm::vec2 &v)
		{
			yaml[0].Extract(v.x);
			yaml[1].Extract(v.y);
		}
	};

	using Vector2Serializer = YamlSerializer<glm::vec2>;
}