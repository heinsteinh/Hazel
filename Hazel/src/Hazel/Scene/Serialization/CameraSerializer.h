#pragma once

#include "Hazel/Scene/Components/CameraComponent.h"
#include "Hazel/Core/Yaml/YamlSerializer.h"

namespace Hazel
{
	template<>
	struct YamlSerializer<CameraComponent>
	{
		static void Serialize(YamlDocument &document, const CameraComponent &value)
		{
			document.BeginMap()
				.Write("ProjectionType", static_cast<int>(value.Projection.ProjectionType))
				.Write("OrthographicAspectRatio", value.Projection.OrthographicProjection.AspectRatio)
				.Write("OrthographicSize", value.Projection.OrthographicProjection.Size)
				.Write("OrthographicNearClip", value.Projection.OrthographicProjection.NearClip)
				.Write("OrthographicFarClip", value.Projection.OrthographicProjection.FarClip)
				.Write("PerspectiveAspectRatio", value.Projection.PerspectiveProjection.AspectRatio)
				.Write("PerspectiveVerticalFov", value.Projection.PerspectiveProjection.VerticalFov)
				.Write("PerspectiveNearClip", value.Projection.PerspectiveProjection.NearClip)
				.Write("PerspectiveFarClip", value.Projection.PerspectiveProjection.FarClip)
				.EndMap();
		}

		static void Deserialize(const YamlValue &source, CameraComponent &value)
		{
			source["ProjectionType"].Extract(reinterpret_cast<int &>(value.Projection.ProjectionType));
			source["OrthographicAspectRatio"].Extract(value.Projection.OrthographicProjection.AspectRatio);
			source["OrthographicSize"].Extract(value.Projection.OrthographicProjection.Size);
			source["OrthographicNearClip"].Extract(value.Projection.OrthographicProjection.NearClip);
			source["OrthographicFarClip"].Extract(value.Projection.OrthographicProjection.FarClip);
			source["PerspectiveAspectRatio"].Extract(value.Projection.PerspectiveProjection.AspectRatio);
			source["PerspectiveVerticalFov"].Extract(value.Projection.PerspectiveProjection.VerticalFov);
			source["PerspectiveNearClip"].Extract(value.Projection.PerspectiveProjection.NearClip);
			source["PerspectiveFarClip"].Extract(value.Projection.PerspectiveProjection.FarClip);
		}
	};

	using CameraSerializer = YamlSerializer<CameraComponent>;
}