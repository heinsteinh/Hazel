#pragma once

#include "Hazel/Core/Camera/Camera.h"
#include "Hazel/Rendering/GraphicsContext/GraphicsContext.h"
#include "Hazel/Rendering/GraphicsContext/DrawCommand.h"
#include "Hazel/Rendering/Renderer/RendererStatistics.h"
#include "RendererBatch.h"
#include "RendererBuffers.h"

namespace Hazel
{
	struct RendererContext
	{
		GraphicsContext *GraphicsContext = nullptr;
		const Camera *Camera = nullptr;
		DrawCommand Command;
		RendererBatch Batch;
		RendererBuffers Buffers;
		RendererStatistics Statistics;

		RendererContext(const RendererInfo &info)
			: GraphicsContext(info.GraphicsContext),
			Batch(info),
			Buffers(info),
			Statistics(info)
		{
			Buffers.Bind(Command);
			Batch.SetIndexFormat(Command.IndexFormat);
		}
	};
}