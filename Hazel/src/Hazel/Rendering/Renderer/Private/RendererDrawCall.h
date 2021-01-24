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
			context.Buffers.BufferIndices(context.Batch);
			context.Buffers.BufferVertices(context.Batch);
			BufferTextures(context);
		}

		static void BufferTextures(RendererContext &context)
		{
			context.Command.Textures.clear();
			auto &textures = context.Batch.GetTextures();
			for (size_t slot = 0; slot < textures.GetTextureCount(); slot++)
			{
				context.Command.Textures.push_back(textures.GetTexture(slot));
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