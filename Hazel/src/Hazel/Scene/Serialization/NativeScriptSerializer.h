#pragma once

#include "Hazel/Scene/Components/NativeScriptComponent.h"
#include "Hazel/Core/Yaml/YamlSerializer.h"

namespace Hazel
{
	template<>
	struct YamlSerializer<NativeScriptComponent>
	{
		static void Serialize(YamlDocument &document, const NativeScriptComponent &value)
		{
			document.BeginMap()
				.Write("Type", value.GetTypeName())
				.EndMap();
		}

		static void Deserialize(const YamlValue &source, NativeScriptComponent &value)
		{
		}
	};

	using NativeScriptSerializer = YamlSerializer<NativeScriptComponent>;
}