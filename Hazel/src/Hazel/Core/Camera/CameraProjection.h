#pragma once

#include "Hazel/Core/Geometry/ProjectionType.h"
#include "Hazel/Core/Geometry/OrthographicProjection.h"
#include "Hazel/Core/Geometry/PerspectiveProjection.h"

namespace Hazel
{
	struct CameraProjection
	{
		ProjectionType ProjectionType = ProjectionType::Orthographic;
		OrthographicProjection OrthographicProjection;
		PerspectiveProjection PerspectiveProjection;

		glm::mat4 ToMatrix() const
		{
			switch (ProjectionType)
			{
			case ProjectionType::Orthographic:
				return OrthographicProjection.ToMatrix();
			case ProjectionType::Perspective:
				return PerspectiveProjection.ToMatrix();
			}
			return glm::mat4(1.0f);
		}

		void SetAspectRatio(float aspectRatio)
		{
			OrthographicProjection.AspectRatio = aspectRatio;
			PerspectiveProjection.AspectRatio = aspectRatio;
		}
	};
}