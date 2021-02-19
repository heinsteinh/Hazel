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
				SortByZCoordinate(context);
				break;
			case ProjectionType::Perspective:
				SortByCameraDistance(context);
				break;
			}
		}

	private:
		static void SortByZCoordinate(RendererContext &context)
		{
			context.RenderQueue.Sort([&](const auto &left, const auto &right)
			{
				if (left.Transparency || right.Transparency)
				{
					return RenderCommandComparator::CompareTransparency(left, right)
						|| RenderCommandComparator::CompareZCoordinate(left, right)
						|| RenderCommandComparator::ComparePipeline(left, right);
				}
				return RenderCommandComparator::ComparePipeline(left, right);
			});
		}

		static void SortByCameraDistance(RendererContext &context)
		{
			context.RenderQueue.Sort([&](const auto &left, const auto &right)
			{
				if (left.Transparency || right.Transparency)
				{
					return RenderCommandComparator::CompareTransparency(left, right)
						|| RenderCommandComparator::CompareCameraDistance(left, right, context.CameraPosition)
						|| RenderCommandComparator::ComparePipeline(left, right);
				}
				return RenderCommandComparator::ComparePipeline(left, right);
			});
		}
	};
}