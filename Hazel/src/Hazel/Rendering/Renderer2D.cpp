#include "Renderer2D.h"

#include "Hazel/Rendering/Textures/TextureBuilder.h"
#include "Batch/DefaultBatchInfo.h"

namespace Hazel
{
	Renderer2D::Renderer2D(const Context &context)
		: Renderer2D(context, DefaultBatchInfo::Create(context.Factory))
	{
	}

	Renderer2D::Renderer2D(const Context &context, const BatchInfo &batchInfo)
		: drawer(context.Drawer),
		shader(context.Factory),
		batch(batchInfo)
	{
		shader.Bind();
		shader.UploadSamplerIds(batch.GetMaxTextures());
	}

	void Renderer2D::BeginScene(const OrthographicCamera &camera)
	{
		drawer.Clear();
		shader.SetViewProjectionMatrix(camera.GetViewProjectionMatrix());
	}

	void Renderer2D::Draw(const GameObject &object)
	{
		if (!batch.Add(object.GetDrawData()))
		{
			EndScene();
			if (!batch.Add(object.GetDrawData()))
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