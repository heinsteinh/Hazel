#pragma once

#include "glm/gtc/quaternion.hpp"

#include "YamlDocument.h"

namespace Hazel
{
	struct YamlSerializer
	{
		template<typename T>
		static void Serialize(YamlDocument &document, const T &value)
		{
			static_assert(false, "Please specialize this method to serialize this type");
		}

		static void YamlSerializer::Serialize(YamlDocument &document, const glm::vec2 &value)
		{
			document.InlineBlock()
				.BeginSequence()
				.Write(value.x)
				.Write(value.y)
				.EndSequence();
		}

		static void YamlSerializer::Serialize(YamlDocument &document, const glm::vec3 &value)
		{
			document.InlineBlock()
				.BeginSequence()
				.Write(value.x)
				.Write(value.y)
				.Write(value.z)
				.EndSequence();
		}

		static void YamlSerializer::Serialize(YamlDocument &document, const glm::vec4 &value)
		{
			document.InlineBlock()
				.BeginSequence()
				.Write(value.x)
				.Write(value.y)
				.Write(value.z)
				.Write(value.w)
				.EndSequence();
		}

		static void YamlSerializer::Serialize(YamlDocument &document, const glm::quat &value)
		{
			document.InlineBlock()
				.BeginSequence()
				.Write(value.x)
				.Write(value.y)
				.Write(value.z)
				.Write(value.w)
				.EndSequence();
		}
	};
}