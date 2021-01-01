#pragma once

#include "Hazel/Core/Geometry/Rectangle.h"
#include "YamlSerializer.h"

namespace Hazel
{
	template<>
	struct YamlSerializer<Rectangle>
	{
		static void Serialize(YamlDocument &document, const Rectangle &value)
		{
			document.InlineBlock()
				.BeginSequence()
				.Write(value.Left)
				.Write(value.Right)
				.Write(value.Bottom)
				.Write(value.Top)
				.EndSequence();
		}

		static void Deserialize(const YamlValue &source, Rectangle &value)
		{
			source[0].Extract(value.Left);
			source[1].Extract(value.Right);
			source[2].Extract(value.Bottom);
			source[3].Extract(value.Top);
		}
	};

	using RectangleSerializer = YamlSerializer<Rectangle>;
}