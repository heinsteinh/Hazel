#include "Renderer2D.h"

#include "Hazel/Textures/TextureBuilder.h"

namespace Hazel
{
	Renderer2D::Renderer2D(const RendererInfo &info)
		: info(info),
		batch(info),
		shader(*info.GraphicsContext)
	{
		info.GraphicsContext->SetShader(shader);
		info.GraphicsContext->SetIndexFormat(info.IndexFormat);
		shader.InitSamplers(batch.GetMaxTextures());
		batch.BindBuffers();
	}

	void Renderer2D::BeginScene(const OrthographicCamera &camera)
	{
		shader.SetViewProjectionMatrix(camera.GetViewProjectionMatrix());
		statistics.Reset();
	}

	void Renderer2D::Render(const DrawData &drawData)
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

	void Renderer2D::EndScene()
	{
		batch.BindTextures();
		batch.BufferData();
		info.GraphicsContext->DrawIndexed(batch.GetIndexCount());
		statistics.DrawCallCount++;
		statistics.IndexCount += batch.GetIndexCount();
		statistics.VertexCount += batch.GetVertexCount();
		statistics.TextureCount = batch.GetTextureCount();
		batch.Clear();
	}
}