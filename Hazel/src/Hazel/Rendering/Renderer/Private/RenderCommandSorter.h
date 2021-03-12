#pragma once

#include "RendererPrivate.h"
#include "RenderCommandComparator.h"

namespace Hazel
{
	class RenderCommandSorter
	{
	public:
		static void SortRenderQueue(RendererPrivate &renderer)
		{
			switch (renderer.CameraProjectionType)
			{
			case ProjectionType::Orthographic:
				SortForOrthographicProjection(renderer);
				break;
			case ProjectionType::Perspective:
				SortForPerspectiveProjection(renderer);
				break;
			}
		}

	private:
		static void SortForOrthographicProjection(RendererPrivate &renderer)
		{
			renderer.RenderQueue.Sort([&](const auto &left, const auto &right)
			{
				return RenderCommandComparator::CompareForOrthographicProjection(left, right);
			});
		}

		static void SortForPerspectiveProjection(RendererPrivate &renderer)
		{
			renderer.RenderQueue.Sort([&](const auto &left, const auto &right)
			{
				return RenderCommandComparator::CompareForPerspectiveProjection(left, right, renderer.CameraPosition);
			});
		}
	};
}