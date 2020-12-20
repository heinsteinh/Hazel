#pragma once

#include "yaml-cpp/yaml.h"

#include "Hazel/Scene/Components/NativeScriptComponent.h"

namespace Hazel
{
	class NativeScriptSerializer
	{
	public:
		static void Serialize(const NativeScriptComponent &script, YAML::Emitter &emitter)
		{
			emitter << YAML::BeginMap;
			emitter << YAML::Key << "Type" << YAML::Value << script.GetTypeName();
			emitter << YAML::EndMap;
		}
	};

	inline YAML::Emitter &operator<<(YAML::Emitter &emitter, const NativeScriptComponent &script)
	{
		NativeScriptSerializer::Serialize(script, emitter);
		return emitter;
	}
}