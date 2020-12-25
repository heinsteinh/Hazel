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
			auto screenAspectRatio = component.Projection.OrthographicProjection.AspectRatio;
			Parse(source, component.Projection);
			component.Projection.SetAspectRatio(screenAspectRatio);
		}

		static void Parse(const YamlValue &source, CameraProjection &projection)
		{
			Parse(source["ProjectionType"], projection.ProjectionType);
			Parse(source["OrthographicProjection"], projection.OrthographicProjection);
			Parse(source["PerspectiveProjection"], projection.PerspectiveProjection);
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
	void YamlParser::Parse(const YamlValue &source, CameraProjection &value)
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