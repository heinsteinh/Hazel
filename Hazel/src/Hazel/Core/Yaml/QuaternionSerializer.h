#pragma once

#include "glm/gtc/quaternion.hpp"

#include "YamlSerializer.h"

namespace Hazel
{
	template<>
	struct YamlSerializer<glm::quat>
	{
		static void Serialize(YamlDocument &yaml, const glm::quat &q)
		{
			yaml.InlineBlock()
				.BeginSequence()
				.Write(q.x)
				.Write(q.y)
				.Write(q.z)
				.Write(q.w)
				.EndSequence();
		}

		static void Deserialize(const YamlValue &yaml, glm::quat &q)
		{
			yaml[0].Extract(q.x);
			yaml[1].Extract(q.y);
			yaml[2].Extract(q.z);
			yaml[3].Extract(q.w);
		}
	};

	using QuaternionSerializer = YamlSerializer<glm::quat>;
}