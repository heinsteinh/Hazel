#include "BatchRenderer.h"

namespace Hazel
{
	BatchRenderer::BatchRenderer(GraphicsContext &graphicsContext, const BatchInfo &info)
		: graphicsContext(&graphicsContext),
		batch(graphicsContext, info)
	{
		graphicsContext.SetIndexFormat(info.IndexFormat);
		graphicsContext.SetPrimitiveTopology(info.PrimitiveTopology);
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
		statistics.TextureCount = batch.GetTextureCount();
		batch.Clear();
	}
}