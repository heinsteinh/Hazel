#pragma once

#include "glm/gtc/quaternion.hpp"

#include "YamlSerializer.h"

namespace Hazel
{
	template<>
	struct YamlSerializer<glm::quat>
	{
		static void Serialize(YamlDocument &document, const glm::quat &value)
		{
			document.InlineBlock()
				.BeginSequence()
				.Write(value.x)
				.Write(value.y)
				.Write(value.z)
				.Write(value.w)
				.EndSequence();
		}

		static void Deserialize(const YamlValue &source, glm::quat &value)
		{
			source[0].Extract(value.x);
			source[1].Extract(value.y);
			source[2].Extract(value.z);
			source[3].Extract(value.w);
		}
	};

	using QuaternionSerializer = YamlSerializer<glm::quat>;
}