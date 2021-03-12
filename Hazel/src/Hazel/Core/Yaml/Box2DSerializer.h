#pragma once

#include "Hazel/Core/Geometry/Box2D.h"
#include "YamlSerializer.h"

namespace Hazel
{
	template<>
	struct YamlSerializer<Box2D>
	{
		static void Serialize(YamlDocument &yaml, const Box2D &box)
		{
			yaml.InlineBlock()
				.BeginSequence()
				.Write(box.Min.x)
				.Write(box.Max.x)
				.Write(box.Min.y)
				.Write(box.Max.y)
				.EndSequence();
		}

		static void Deserialize(const YamlValue &yaml, Box2D &box)
		{
			yaml[0].Extract(box.Min.x);
			yaml[1].Extract(box.Max.x);
			yaml[2].Extract(box.Min.y);
			yaml[3].Extract(box.Max.y);
		}
	};

	using Box2DSerializer = YamlSerializer<Box2D>;
}