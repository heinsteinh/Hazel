#pragma once

#include "glm/gtc/quaternion.hpp"

#include "YamlValue.h"

namespace Hazel
{
	struct YamlParser
	{
		template<typename T>
		static void Parse(const YamlValue &source, T &value)
		{
			static_assert(false, "Please specialize this method to parse this type");
		}

		static void Parse(const YamlValue &source, glm::vec2 &value)
		{
			source[0].Extract(value.x);
			source[1].Extract(value.y);
		}

		static void Parse(const YamlValue &source, glm::vec3 &value)
		{
			source[0].Extract(value.x);
			source[1].Extract(value.y);
			source[2].Extract(value.z);
		}

		static void Parse(const YamlValue &source, glm::vec4 &value)
		{
			source[0].Extract(value.x);
			source[1].Extract(value.y);
			source[2].Extract(value.z);
			source[3].Extract(value.w);
		}

		static void Parse(const YamlValue &source, glm::quat &value)
		{
			source[0].Extract(value.x);
			source[1].Extract(value.y);
			source[2].Extract(value.z);
			source[3].Extract(value.w);
		}
	};
}