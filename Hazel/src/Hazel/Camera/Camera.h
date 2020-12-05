#pragma once

#include "Hazel/Geometry/MvpMatrix.h"
#include "Hazel/Geometry/Size.h"

namespace Hazel
{
	class Camera
	{
	private:
		ProjectionInfo projectionInfo;
		glm::mat4 projection{1.0f};

	public:
		const ProjectionInfo &GetProjectionInfo() const
		{
			return projectionInfo;
		}

		void SetProjectionInfo(const ProjectionInfo &projectionInfo)
		{
			this->projectionInfo = projectionInfo;
			RecomputeProjection();
		}

		void SetViewport(const glm::vec2 &viewport)
		{
			projectionInfo.AspectRatio = Size::GetAspectRatio(viewport);
			RecomputeProjection();
		}

		float GetZoomLevel() const
		{
			return projectionInfo.OrthographicsSize;
		}

		void SetZoomLevel(float zoomLevel)
		{
			projectionInfo.OrthographicsSize = zoomLevel;
			RecomputeProjection();
		}

		const glm::mat4 &GetProjection() const
		{
			return projection;
		}

	private:
		void RecomputeProjection()
		{
			projection = MvpMatrix::GetOrthographicProjection(projectionInfo);
		}
	};
}