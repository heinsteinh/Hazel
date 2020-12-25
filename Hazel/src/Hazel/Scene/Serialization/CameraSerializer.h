#pragma once

#include "Hazel/Scene/Components/CameraComponent.h"
#include "Hazel/Core/Yaml/YamlSerializer.h"

namespace Hazel
{
	class CameraSerializer
	{
	public:
		static void Serialize(YamlDocument &document, const CameraComponent &component)
		{
			Serialize(document, component.Projection);
		}

		static void Serialize(YamlDocument &document, const CameraProjection &projection)
		{
			document.BeginMap();
			document.Key().Write("ProjectionType").Value();
			Serialize(document, projection.ProjectionType);
			document.Key().Write("OrthographicProjection").Value();
			Serialize(document, projection.OrthographicProjection);
			document.Key().Write("PerspectiveProjection").Value();
			Serialize(document, projection.PerspectiveProjection);
			document.EndMap();
		}

		static void Serialize(YamlDocument &document, ProjectionType projectionType)
		{
			document.Write(static_cast<int>(projectionType));
		}

		static void Serialize(YamlDocument &document, const OrthographicProjection &projection)
		{
			document.BeginMap()
				.Key().Write("AspectRatio").Value().Write(projection.AspectRatio)
				.Key().Write("Size").Value().Write(projection.Size)
				.Key().Write("NearClip").Value().Write(projection.NearClip)
				.Key().Write("FarClip").Value().Write(projection.FarClip)
				.EndMap();
		}

		static void Serialize(YamlDocument &document, const PerspectiveProjection &projection)
		{
			document.BeginMap()
				.Key().Write("AspectRatio").Value().Write(projection.AspectRatio)
				.Key().Write("VerticalFov").Value().Write(projection.VerticalFov)
				.Key().Write("NearClip").Value().Write(projection.NearClip)
				.Key().Write("FarClip").Value().Write(projection.FarClip)
				.EndMap();
		}
	};

	template<>
	inline void YamlSerializer::Serialize(YamlDocument &document, const CameraComponent &value)
	{
		CameraSerializer::Serialize(document, value);
	}

	template<>
	inline void YamlSerializer::Serialize(YamlDocument &document, const CameraProjection &value)
	{
		CameraSerializer::Serialize(document, value);
	}

	template<>
	inline void YamlSerializer::Serialize(YamlDocument &document, const ProjectionType &value)
	{
		CameraSerializer::Serialize(document, value);
	}

	template<>
	inline void YamlSerializer::Serialize(YamlDocument &document, const OrthographicProjection &value)
	{
		CameraSerializer::Serialize(document, value);
	}

	template<>
	inline void YamlSerializer::Serialize(YamlDocument &document, const PerspectiveProjection &value)
	{
		CameraSerializer::Serialize(document, value);
	}
}