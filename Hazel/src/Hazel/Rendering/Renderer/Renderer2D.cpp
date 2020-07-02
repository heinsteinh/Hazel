#include "Renderer2D.h"

#include "Hazel/Rendering/Textures/TextureBuilder.h"
#include "DefaultShaderInfo.h"
#include "DefaultBatchInfo.h"

namespace Hazel
{
	Renderer2D::Renderer2D(const Context &context)
		: drawer(context.Drawer),
		shader(context.Factory.CreateShader(DefaultShaderInfo::Get())),
		whiteTexture(TextureBuilder(context.Factory).Build(glm::vec4(1.0f))),
		batchInfo(DefaultBatchInfo::Create(context.Factory)),
		batch(batchInfo)
	{
		std::vector<int> samplers;
		samplers.reserve(batchInfo.MaxTextures);
		for (size_t i = 0; i < batchInfo.MaxTextures; i++)
		{
			samplers.push_back(static_cast<int>(i));
		}
		shader->Bind();
		shader->Set("u_Textures", samplers.data(), samplers.size());
	}

	void Renderer2D::BeginScene(const OrthographicCamera &camera)
	{
		shader->Set("u_ViewProjection", camera.GetViewProjectionMatrix());
	}

	void Renderer2D::Draw(const GameObject &object)
	{
		batch.Add(object.GetDrawData());
	}

	void Renderer2D::EndScene()
	{
		batch.Bind();
		batch.BufferData();
		drawer.DrawIndexed(batch.GetIndexCount());
		batch.Clear();
	}
}