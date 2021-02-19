#pragma once

#include "RendererContext.h"

namespace Hazel
{
	class RendererDrawCall
	{
	public:
		static void Flush(RendererContext &context)
		{
			if (!context.Batch.IsEmpty())
			{
				UpdateStatistics(context);
				BufferData(context);
				DrawIndexed(context);
			}
		}

	private:
		static void UpdateStatistics(RendererContext &context)
		{
			context.Statistics.IndexCount += context.Batch.GetIndices().GetIndexCount();
			context.Statistics.VertexCount += context.Batch.GetVertices().GetVertexCount();
			context.Statistics.TextureCount += context.Batch.GetTextures().GetTextureCount();
			context.Statistics.DrawCallCount++;
		}

		static void BufferData(RendererContext &context)
		{
			context.Buffers.BufferIndices(context.Batch.GetIndices());
			context.Buffers.BufferVertices(context.Batch.GetVertices());
			BufferTextures(context.Command, context.Batch.GetTextures());
		}

		static void BufferTextures(DrawCommand &command, const RendererTextures &textures)
		{
			command.Textures.clear();
			for (size_t slot = 0; slot < textures.GetTextureCount(); slot++)
			{
				command.Textures.push_back(textures.GetTexture(slot));
			}
		}

		static void DrawIndexed(RendererContext &context)
		{
			context.Command.IndexCount = context.Batch.GetIndices().GetIndexCount();
			context.GraphicsContext->DrawIndexed(context.Command);
			context.Batch.Clear();
		}
	};
}