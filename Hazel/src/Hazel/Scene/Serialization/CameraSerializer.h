#pragma once

#include "yaml-cpp/yaml.h"

#include "Hazel/Scene/Components/CameraComponent.h"
#include "GeometrySerializer.h"

namespace Hazel
{
	YAML::Emitter &operator<<(YAML::Emitter &emitter, const OrthographicProjection &projection);
	YAML::Emitter &operator<<(YAML::Emitter &emitter, const PerspectiveProjection &projection);

	class CameraSerializer
	{
	public:
		static void Serialize(const CameraComponent &camera, YAML::Emitter &emitter)
		{
			Serialize(camera.Camera, emitter);
		}

		static void Serialize(const Camera &camera, YAML::Emitter &emitter)
		{
			emitter << YAML::BeginMap;
			emitter << YAML::Key << "ProjectionType" << YAML::Value << static_cast<int>(camera.GetProjectionType());
			emitter << YAML::Key << "OrthographicProjection" << YAML::Value << camera.GetOrthographicProjection();
			emitter << YAML::Key << "PerspectiveProjection" << YAML::Value << camera.GetPerspectiveProjection();
			emitter << YAML::EndMap;
		}

		static void Serialize(const OrthographicProjection &projection, YAML::Emitter &emitter)
		{
			emitter << YAML::BeginMap;
			emitter << YAML::Key << "AspectRatio" << YAML::Value << projection.AspectRatio;
			emitter << YAML::Key << "Size" << YAML::Value << projection.Size;
			emitter << YAML::Key << "NearClip" << YAML::Value << projection.NearClip;
			emitter << YAML::Key << "FarClip" << YAML::Value << projection.FarClip;
			emitter << YAML::EndMap;
		}

		static void Serialize(const PerspectiveProjection &projection, YAML::Emitter &emitter)
		{
			emitter << YAML::BeginMap;
			emitter << YAML::Key << "AspectRatio" << YAML::Value << projection.AspectRatio;
			emitter << YAML::Key << "VerticalFov" << YAML::Value << projection.VerticalFov;
			emitter << YAML::Key << "NearClip" << YAML::Value << projection.NearClip;
			emitter << YAML::Key << "FarClip" << YAML::Value << projection.FarClip;
			emitter << YAML::EndMap;
		}
	};

	inline YAML::Emitter &operator<<(YAML::Emitter &emitter, const CameraComponent &camera)
	{
		CameraSerializer::Serialize(camera, emitter);
		return emitter;
	}

	inline YAML::Emitter &operator<<(YAML::Emitter &emitter, const Camera &camera)
	{
		CameraSerializer::Serialize(camera, emitter);
		return emitter;
	}

	inline YAML::Emitter &operator<<(YAML::Emitter &emitter, const OrthographicProjection &projection)
	{
		CameraSerializer::Serialize(projection, emitter);
		return emitter;
	}

	inline YAML::Emitter &operator<<(YAML::Emitter &emitter, const PerspectiveProjection &projection)
	{
		CameraSerializer::Serialize(projection, emitter);
		return emitter;
	}
}