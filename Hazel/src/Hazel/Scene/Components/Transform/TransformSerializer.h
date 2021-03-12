#pragma once

#include "Hazel/Core/Geometry/Transform.h"
#include "Hazel/Core/Yaml/Vector3Serializer.h"
#include "Hazel/Core/Yaml/QuaternionSerializer.h"

namespace Hazel
{
	template<>
	struct YamlSerializer<Transform>
	{
		static void Serialize(YamlDocument &yaml, const Transform &transform)
		{
			yaml.BeginMap()
				.Write("Translation", transform.Translation)
				.Write("Rotation", transform.Rotation)
				.Write("Scale", transform.Scale)
				.EndMap();
		}

		static void Deserialize(const YamlValue &yaml, Transform &transform)
		{
			yaml["Translation"].Extract(transform.Translation);
			yaml["Rotation"].Extract(transform.Rotation);
			yaml["Scale"].Extract(transform.Scale);
		}
	};

	using TransformSerializer = YamlSerializer<Transform>;
}