#pragma once

#include "glm/glm.hpp"

#include "YamlSerializer.h"

namespace Hazel
{
	template<>
	struct YamlSerializer<glm::vec4>
	{
		static void Serialize(YamlDocument &document, const glm::vec4 &value)
		{
			document.InlineBlock()
				.BeginSequence()
				.Write(value.x)
				.Write(value.y)
				.Write(value.z)
				.Write(value.w)
				.EndSequence();
		}

		static void Deserialize(const YamlValue &source, glm::vec4 &value)
		{
			source[0].Extract(value.x);
			source[1].Extract(value.y);
			source[2].Extract(value.z);
			source[3].Extract(value.w);
		}
	};

	using Vector4Serializer = YamlSerializer<glm::vec4>;
}