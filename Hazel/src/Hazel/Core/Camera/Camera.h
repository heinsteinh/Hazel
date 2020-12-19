#pragma once

#include "Hazel/Core/Geometry/ProjectionType.h"
#include "Hazel/Core/Geometry/OrthographicProjection.h"
#include "Hazel/Core/Geometry/PerspectiveProjection.h"
#include "Hazel/Core/Geometry/Rectangle.h"

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
		void SetProjectionType(ProjectionType projectionType);
		void SetOrthographicProjection(const OrthographicProjection &orthographicProjection);
		void SetPerspectiveProjection(const PerspectiveProjection &perspectiveProjection);

		ProjectionType GetProjectionType() const
		{
			return projectionType;
		}

		const OrthographicProjection &GetOrthographicProjection() const
		{
			return orthographicProjection;
		}

		const PerspectiveProjection &GetPerspectiveProjection() const
		{
			return perspectiveProjection;
		}

		const glm::mat4 &GetProjection() const
		{
			return projection;
		}

	private:
		void RecomputeProjection();
	};
}