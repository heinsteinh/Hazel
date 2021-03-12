#pragma once

#include "Hazel/Core/Camera/CameraProjection.h"
#include "Hazel/Core/Yaml/YamlSerializer.h"

namespace Hazel
{
	template<>
	struct YamlSerializer<CameraProjection>
	{
		static void Serialize(YamlDocument &yaml, const CameraProjection &camera)
		{
			yaml.BeginMap()
				.Write("ProjectionType", static_cast<int>(camera.ProjectionType))
				.Write("OrthographicSize", camera.OrthographicProjection.Size)
				.Write("OrthographicNearClip", camera.OrthographicProjection.NearClip)
				.Write("OrthographicFarClip", camera.OrthographicProjection.FarClip)
				.Write("PerspectiveVerticalFov", camera.PerspectiveProjection.VerticalFov)
				.Write("PerspectiveNearClip", camera.PerspectiveProjection.NearClip)
				.Write("PerspectiveFarClip", camera.PerspectiveProjection.FarClip)
				.EndMap();
		}

		static void Deserialize(const YamlValue &yaml, CameraProjection &camera)
		{
			yaml["ProjectionType"].Extract(reinterpret_cast<int &>(camera.ProjectionType));
			yaml["OrthographicSize"].Extract(camera.OrthographicProjection.Size);
			yaml["OrthographicNearClip"].Extract(camera.OrthographicProjection.NearClip);
			yaml["OrthographicFarClip"].Extract(camera.OrthographicProjection.FarClip);
			yaml["PerspectiveVerticalFov"].Extract(camera.PerspectiveProjection.VerticalFov);
			yaml["PerspectiveNearClip"].Extract(camera.PerspectiveProjection.NearClip);
			yaml["PerspectiveFarClip"].Extract(camera.PerspectiveProjection.FarClip);
		}
	};

	using CameraSerializer = YamlSerializer<CameraProjection>;
}