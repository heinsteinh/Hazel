#pragma once

#include "glm/glm.hpp"

#include "YamlSerializer.h"

namespace Hazel
{
	template<>
	struct YamlSerializer<glm::vec2>
	{
		static void Serialize(YamlDocument &document, const glm::vec2 &value)
		{
			document.InlineBlock()
				.BeginSequence()
				.Write(value.x)
				.Write(value.y)
				.EndSequence();
		}

		static void Deserialize(const YamlValue &source, glm::vec2 &value)
		{
			source[0].Extract(value.x);
			source[1].Extract(value.y);
		}
	};

	using Vector2Serializer = YamlSerializer<glm::vec2>;
}