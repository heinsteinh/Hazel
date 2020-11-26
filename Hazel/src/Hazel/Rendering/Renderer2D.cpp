#include "Renderer2D.h"

#include "Hazel/Textures/TextureBuilder.h"

namespace Hazel
{
	BatchInfo Renderer2D::GetBatchInfo(const RendererInfo &rendererInfo)
	{
		BatchInfo batchInfo;
		batchInfo.MaxIndexCount = rendererInfo.MaxIndexCount;
		batchInfo.MaxVertexCount = rendererInfo.MaxVertexCount;
		batchInfo.MaxTextureSlotCount = rendererInfo.GraphicsContext->GetMaxTextureSlotCount();
		batchInfo.IndexFormat = rendererInfo.IndexFormat;
		return batchInfo;
	}

	Renderer2D::Renderer2D(const RendererInfo &info)
		: info(info),
		batchRenderer(*info.GraphicsContext, GetBatchInfo(info))
	{
	}

	void Renderer2D::BeginScene(const OrthographicCamera &camera)
	{
		batchRenderer.BeginScene(camera.GetViewProjectionMatrix());
	}

	void Renderer2D::Render(const DrawData &drawData)
	{
		batchRenderer.Render(drawData);
	}

	void Renderer2D::EndScene()
	{
		batchRenderer.EndScene();
	}
}