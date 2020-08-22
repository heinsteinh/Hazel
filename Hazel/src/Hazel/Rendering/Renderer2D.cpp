#include "Renderer2D.h"

#include "Hazel/Textures/TextureBuilder.h"

namespace Hazel
{
	Renderer2D::Renderer2D(const Context &context)
		: drawer(context.Drawer),
		shader(context.Factory),
		batchInfo({60000, 40000, 32}),
		batch(context.Factory)
	{
		Init(batchInfo);
	}

	void Renderer2D::Init(const BatchInfo &info)
	{
		batchInfo = info;
		shader.Bind();
		shader.InitSamplers(batch.GetMaxTextures());
		batch.Init(info);
	}

	void Renderer2D::BeginScene(const OrthographicCamera &camera)
	{
		drawer.Clear();
		shader.SetViewProjectionMatrix(camera.GetViewProjectionMatrix());
		statistics = RendererStatistics();
	}

	void Renderer2D::Draw(const DrawData &drawData)
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
		batch.Bind();
		batch.BufferData();
		drawer.DrawIndexed(batch.GetIndexCount());
		statistics.DrawCallCount++;
		statistics.IndexCount += batch.GetIndexCount();
		statistics.VertexCount += batch.GetVertexCount();
		statistics.TextureCount += batch.GetTextureCount();
		batch.Clear();
	}
}