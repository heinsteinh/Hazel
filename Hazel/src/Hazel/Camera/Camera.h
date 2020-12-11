#pragma once

#include "Hazel/Geometry/ProjectionType.h"
#include "Hazel/Geometry/OrthographicProjection.h"
#include "Hazel/Geometry/PerspectiveProjection.h"
#include "Hazel/Geometry/Rectangle.h"

namespace Hazel
{
	class Camera
	{
	private:
		ProjectionType projectionType = ProjectionType::Orthographic;
		OrthographicProjection orthographicProjection;
		PerspectiveProjection perspectiveProjection;
		glm::mat4 projection{1.0f};

	public:
		void SetViewport(const Rectangle &viewport);
		float GetZoomLevel() const;
		void SetZoomLevel(float zoomLevel);

		ProjectionType GetProjectionType() const
		{
			return projectionType;
		}

		void SetProjectionType(ProjectionType projectionType)
		{
			this->projectionType = projectionType;
		}

		const OrthographicProjection &GetOrthographicProjection() const
		{
			return orthographicProjection;
		}

		void SetOrthographicProjectionInfo(const OrthographicProjection &orthographicProjection)
		{
			this->orthographicProjection = orthographicProjection;
		}

		const PerspectiveProjection &GetPerspectiveProjection() const
		{
			return perspectiveProjection;
		}

		void SetPerspectiveProjectionInfo(const PerspectiveProjection &perspectiveProjection)
		{
			this->perspectiveProjection = perspectiveProjection;
		}

		const glm::mat4 &GetProjection() const
		{
			return projection;
		}

	private:
		void RecomputeProjection();
	};
}