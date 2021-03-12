#pragma once

#include "Hazel/Core/Yaml/YamlSerializer.h"
#include "Hazel/Scene/Assets/Script.h"

namespace Hazel
{
	template<>
	struct YamlSerializer<Script>
	{
		static void Serialize(YamlDocument &yaml, const Script &script)
		{
			yaml.BeginMap()
				.Write("Name", script.GetName())
				.EndMap();
		}

		static void Deserialize(const YamlValue &yaml, Script &script)
		{
		}

		static std::string GetScriptName(const YamlValue &yaml)
		{
			return yaml["Name"].GetValueOr(std::string());
		}
	};

	using ScriptSerializer = YamlSerializer<Script>;
}