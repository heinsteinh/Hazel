#pragma once

#include "Hazel/Scene/Components/NativeScriptComponent.h"
#include "Hazel/Core/Yaml/YamlSerializer.h"

namespace Hazel
{
	class NativeScriptSerializer
	{
	public:
		static void Serialize(YamlDocument &document, const NativeScriptComponent &component)
		{
			document.BeginMap()
				.Key().Write("Type").Value().Write(component.GetTypeName())
				.EndMap();
		}
	};

	template<>
	void YamlSerializer::Serialize(YamlDocument &document, const NativeScriptComponent &value)
	{
		NativeScriptSerializer::Serialize(document, value);
	}
}