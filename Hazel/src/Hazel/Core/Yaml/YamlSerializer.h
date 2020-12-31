#pragma once

#include "YamlDocument.h"
#include "YamlValue.h"

namespace Hazel
{
	template<typename T>
	struct YamlSerializer
	{
		static void Serialize(YamlDocument &document, const T &value)
		{
			document.WriteBasicType(value);
		}

		static void Deserialize(const YamlValue &source, T &value)
		{
			source.ExtractBasicType(value);
		}
	};
}