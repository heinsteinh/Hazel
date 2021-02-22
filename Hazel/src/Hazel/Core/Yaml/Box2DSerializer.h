#pragma once

#include "Hazel/Core/Geometry/Box2D.h"
#include "YamlSerializer.h"

namespace Hazel
{
	template<>
	struct YamlSerializer<Box2D>
	{
		static void Serialize(YamlDocument &document, const Box2D &value)
		{
			document.InlineBlock()
				.BeginSequence()
				.Write(value.Min.x)
				.Write(value.Max.x)
				.Write(value.Min.y)
				.Write(value.Max.y)
				.EndSequence();
		}

		static void Deserialize(const YamlValue &source, Box2D &value)
		{
			source[0].Extract(value.Min.x);
			source[1].Extract(value.Max.x);
			source[2].Extract(value.Min.y);
			source[3].Extract(value.Max.y);
		}
	};

	using Box2DSerializer = YamlSerializer<Box2D>;
}