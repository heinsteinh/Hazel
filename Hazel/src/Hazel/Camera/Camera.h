#pragma once

#include "Hazel/Geometry/MvpMatrix.h"
#include "Hazel/Geometry/Rectangle.h"

namespace Hazel
{
	class Camera
	{
	private:
		OrthographicProjectionInfo projectionInfo;
		glm::mat4 projection{1.0f};

	public:
		const OrthographicProjectionInfo &GetProjectionInfo() const
		{
			return projectionInfo;
		}

		void SetProjectionInfo(const OrthographicProjectionInfo &projectionInfo)
		{
			this->projectionInfo = projectionInfo;
			RecomputeProjection();
		}

		void SetViewport(const Rectangle &viewport)
		{
			projectionInfo.AspectRatio = viewport.GetAspectRatio();
			RecomputeProjection();
		}

		float GetZoomLevel() const
		{
			return projectionInfo.Size;
		}

		void SetZoomLevel(float zoomLevel)
		{
			projectionInfo.Size = zoomLevel;
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