#pragma once

#include "Hazel/Core/Yaml/YamlSerializer.h"
#include "Hazel/Scene/Entity/Entity.h"
#include "Hazel/Scene/Serialization/NativeScriptSerializer.h"

namespace Hazel
{
	class ComponentNativeScript
	{
	public:
		static std::unique_ptr<NativeScript> ExtractScript(const YamlValue &source, Entity entity)
		{
			auto script = entity.GetAssetManager().CreateScript(NativeScriptSerializer::GetScriptName(source));
			if (!script)
			{
				script = std::make_unique<NativeScript>();
				script->SetName("EmptyScript");
			}
			return script;
		}
	};
}