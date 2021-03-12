#pragma once

#include "Hazel/Core/Camera/CameraProjection.h"
#include "Private/ProjectionTypeWidget.h"
#include "Private/OrthographicProjectionWidget.h"
#include "Private/PerspectiveProjectionWidget.h"

namespace Hazel
{
	class CameraWidget
	{
	public:
		static bool Draw(CameraProjection &projection)
		{
			bool changed = ProjectionTypeWidget::Draw(projection.ProjectionType);
			switch (projection.ProjectionType)
			{
			case ProjectionType::Orthographic:
				changed |= OrthographicProjectionWidget::Draw(projection.OrthographicProjection);
				break;
			case ProjectionType::Perspective:
				changed |= PerspectiveProjectionWidget::Draw(projection.PerspectiveProjection);
				break;
			}
			return changed;
		}
	};
}