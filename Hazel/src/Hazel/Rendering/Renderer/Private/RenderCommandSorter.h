#pragma once

#include "RendererContext.h"
#include "RenderCommandComparator.h"

namespace Hazel
{
	class RenderCommandSorter
	{
	public:
		static void SortRenderQueue(RendererContext &context)
		{
			switch (context.CameraProjectionType)
			{
			case ProjectionType::Orthographic:
				SortForOrthographicProjection(context);
				break;
			case ProjectionType::Perspective:
				SortForPerspectiveProjection(context);
				break;
			}
		}

	private:
		static void SortForOrthographicProjection(RendererContext &context)
		{
			context.RenderQueue.Sort([&](const auto &left, const auto &right)
			{
				return RenderCommandComparator::CompareForOrthographicProjection(left, right);
			});
		}

		static void SortForPerspectiveProjection(RendererContext &context)
		{
			context.RenderQueue.Sort([&](const auto &left, const auto &right)
			{
				return RenderCommandComparator::CompareForPerspectiveProjection(left, right, context.CameraPosition);
			});
		}
	};
}