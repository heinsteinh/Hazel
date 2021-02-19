#pragma once

#include "Hazel/Core/Camera/CameraProjection.h"
#include "Hazel/Rendering/GraphicsContext/GraphicsContext.h"
#include "Hazel/Rendering/GraphicsContext/DrawCommand.h"
#include "Hazel/Rendering/Renderer/RendererStatistics.h"
#include "Hazel/Rendering/Renderer/RenderQueue.h"
#include "RendererBatch.h"
#include "RendererBuffers.h"

namespace Hazel
{
	struct RendererContext
	{
		GraphicsContext *GraphicsContext = nullptr;
		IndexFormat IndexFormat = IndexFormat::UInt16;
		ProjectionType CameraProjectionType = ProjectionType::Orthographic;
		glm::mat4 ViewProjection{1.0f};
		glm::vec3 CameraPosition{0.0f};
		RenderQueue RenderQueue;
		DrawCommand Command;
		RendererBatch Batch;
		RendererBuffers Buffers;
		RendererStatistics Statistics;

		RendererContext(const RendererInfo &info)
			: GraphicsContext(info.GraphicsContext),
			IndexFormat(info.IndexFormat),
			Batch(info),
			Buffers(info),
			Statistics(info)
		{
			Command.IndexFormat = info.IndexFormat;
			Command.IndexBuffer = Buffers.GetIndexBuffer();
			Command.VertexBuffer = Buffers.GetVertexBuffer();
		}
	};
}