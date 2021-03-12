#pragma once

#include "glm/glm.hpp"

#include "YamlSerializer.h"

namespace Hazel
{
	template<>
	struct YamlSerializer<glm::vec4>
	{
		static void Serialize(YamlDocument &yaml, const glm::vec4 &v)
		{
			yaml.InlineBlock()
				.BeginSequence()
				.Write(v.x)
				.Write(v.y)
				.Write(v.z)
				.Write(v.w)
				.EndSequence();
		}

		static void Deserialize(const YamlValue &yaml, glm::vec4 &v)
		{
			yaml[0].Extract(v.x);
			yaml[1].Extract(v.y);
			yaml[2].Extract(v.z);
			yaml[3].Extract(v.w);
		}
	};

	using Vector4Serializer = YamlSerializer<glm::vec4>;
}