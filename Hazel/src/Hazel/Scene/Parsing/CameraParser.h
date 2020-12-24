#pragma once

#include "Hazel/Scene/Components/CameraComponent.h"
#include "Hazel/Core/Yaml/YamlParser.h"

namespace Hazel
{
	class CameraParser
	{
	public:
		static void Parse(const YamlValue &source, CameraComponent &component)
		{
			auto screenAspectRatio = component.Camera.OrthographicProjection.AspectRatio;
			Parse(source, component.Camera);
			component.Camera.SetAspectRatio(screenAspectRatio);
			component.RecomputeProjection();
		}

		static void Parse(const YamlValue &source, Camera &camera)
		{
			Parse(source["ProjectionType"], camera.ProjectionType);
			Parse(source["OrthographicProjection"], camera.OrthographicProjection);
			Parse(source["PerspectiveProjection"], camera.PerspectiveProjection);
		}

		static void Parse(const YamlValue &source, ProjectionType &projectionType)
		{
			int result = static_cast<int>(projectionType);
			source.Extract(result);
			if (result >= 0 && result < static_cast<int>(ProjectionType::Count))
			{
				projectionType = static_cast<ProjectionType>(projectionType);
			}
		}

		static void Parse(const YamlValue &source, OrthographicProjection &projection)
		{
			source["AspectRatio"].Extract(projection.AspectRatio);
			source["Size"].Extract(projection.Size);
			source["NearClip"].Extract(projection.NearClip);
			source["FarClip"].Extract(projection.FarClip);
		}

		static void Parse(const YamlValue &source, PerspectiveProjection &projection)
		{
			source["AspectRatio"].Extract(projection.AspectRatio);
			source["VerticalFov"].Extract(projection.VerticalFov);
			source["NearClip"].Extract(projection.NearClip);
			source["FarClip"].Extract(projection.FarClip);
		}
	};

	template<>
	void YamlParser::Parse(const YamlValue &source, CameraComponent &value)
	{
		return CameraParser::Parse(source, value);
	}

	template<>
	void YamlParser::Parse(const YamlValue &source, Camera &value)
	{
		return CameraParser::Parse(source, value);
	}

	template<>
	void YamlParser::Parse(const YamlValue &source, ProjectionType &value)
	{
		return CameraParser::Parse(source, value);
	}

	template<>
	void YamlParser::Parse(const YamlValue &source, OrthographicProjection &value)
	{
		return CameraParser::Parse(source, value);
	}

	template<>
	void YamlParser::Parse(const YamlValue &source, PerspectiveProjection &value)
	{
		return CameraParser::Parse(source, value);
	}
}