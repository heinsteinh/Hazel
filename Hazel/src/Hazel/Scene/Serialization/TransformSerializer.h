#pragma once

#include "Hazel/Scene/Components/TransformComponent.h"
#include "Hazel/Core/Yaml/YamlSerializer.h"

namespace Hazel
{
	class TransformSerializer
	{
	public:
		static void Serialize(YamlDocument &document, const TransformComponent &component)
		{
			document.BeginMap()
				.Key().Write("Translation").Value().Write(component.Transform.Translation)
				.Key().Write("EulerHint").Value().Write(component.EulerHint)
				.Key().Write("Scale").Value().Write(component.Transform.Scale)
				.EndMap();
		}

		static void Serialize(YamlDocument &document, const Transform &transform)
		{
			document.BeginMap()
				.Key().Write("Translation").Value().Write(transform.Translation)
				.Key().Write("Rotation").Value().Write(transform.Rotation)
				.Key().Write("Scale").Value().Write(transform.Scale)
				.EndMap();
		}
	};

	template<>
	inline void YamlSerializer::Serialize(YamlDocument &document, const TransformComponent &value)
	{
		return TransformSerializer::Serialize(document, value);
	}

	template<>
	inline void YamlSerializer::Serialize(YamlDocument &document, const Transform &value)
	{
		return TransformSerializer::Serialize(document, value);
	}
}