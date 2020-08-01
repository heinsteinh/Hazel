#include "Renderer2D.h"

#include "Hazel/Rendering/Textures/TextureBuilder.h"

namespace Hazel
{
	Renderer2D::Renderer2D(const Context &context)
		: Renderer2D(context, {40000, 60000, 32})
	{
	}

	Renderer2D::Renderer2D(const Context &context, const BatchInfo &batchInfo)
		: drawer(context.Drawer),
		shader(context.Factory),
		batch(context.Factory, batchInfo)
	{
		shader.Bind();
		shader.InitSamplers(batch.GetMaxTextures());
	}

	void Renderer2D::BeginScene(const OrthographicCamera &camera)
	{
		drawer.Clear();
		shader.SetViewProjectionMatrix(camera.GetViewProjectionMatrix());
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
		batch.Clear();
	}
}