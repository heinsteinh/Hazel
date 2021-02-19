#pragma once

#include "Hazel/Core/Yaml/YamlSerializer.h"
#include "Hazel/Scene/Components/NativeScriptComponent.h"

namespace Hazel
{
	template<>
	struct YamlSerializer<NativeScriptComponent>
	{
		static void Serialize(YamlDocument &document, const NativeScriptComponent &value)
		{
			document.BeginMap()
				.Write("Script", value.Script->GetName())
				.EndMap();
		}

		static void Deserialize(const YamlValue &source, NativeScriptComponent &value)
		{
		}

		static std::string GetScriptName(const YamlValue &source)
		{
			return source["Script"].GetValueOr(std::string());
		}
	};

	using NativeScriptSerializer = YamlSerializer<NativeScriptComponent>;
}