#include "BatchRenderer.h"

namespace Hazel
{
	BatchRenderer::BatchRenderer(GraphicsContext &graphicsContext, const BatchInfo &info)
		: graphicsContext(&graphicsContext),
		batch(graphicsContext, info)
	{
		graphicsContext.SetIndexFormat(info.IndexFormat);
		graphicsContext.SetPrimitiveTopology(info.PrimitiveTopology);
		statistics.MaxVertexCount = info.MaxVertexCount;
		statistics.MaxIndexCount = info.MaxIndexCount;
		statistics.MaxTextureSlotCount = info.MaxTextureSlotCount;
	}

	void BatchRenderer::BeginScene(const glm::mat4 &viewProjectionMatrix)
	{
		statistics.Reset();
		batch.SetViewProjectionMatrix(viewProjectionMatrix);
		batch.BufferConstants();
	}

	void BatchRenderer::Render(const DrawData &drawData)
	{
		if (!batch.Add(drawData))
		{
			EndScene();
			if (!batch.Add(drawData))
			{
				throw BatchException("The batch is too small for the object.");
			}
		}
	}

	void BatchRenderer::EndScene()
	{
		batch.BufferData();
		graphicsContext->DrawIndexed(batch.GetIndexCount());
		statistics.DrawCallCount++;
		statistics.IndexCount += batch.GetIndexCount();
		statistics.VertexCount += batch.GetVertexCount();
		statistics.UsedTextureSlotCount = batch.GetTextureCount();
		batch.Clear();
	}
}