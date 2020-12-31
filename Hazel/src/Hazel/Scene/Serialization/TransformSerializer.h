#pragma once

#include "Hazel/Scene/Components/TransformComponent.h"
#include "Hazel/Core/Yaml/Vector3Serializer.h"
#include "Hazel/Core/Yaml/QuaternionSerializer.h"

namespace Hazel
{
	template<>
	struct YamlSerializer<TransformComponent>
	{
		static void Serialize(YamlDocument &document, const TransformComponent &value)
		{
			document.BeginMap()
				.Write("Translation", value.Transform.Translation)
				.Write("Rotation", value.Transform.Rotation)
				.Write("Scale", value.Transform.Scale)
				.EndMap();
		}

		static void Deserialize(const YamlValue &source, TransformComponent &value)
		{
			source["Translation"].Extract(value.Transform.Translation);
			source["Rotation"].Extract(value.Transform.Rotation);
			source["Scale"].Extract(value.Transform.Scale);
		}
	};

	using TransformSerializer = YamlSerializer<TransformComponent>;
}