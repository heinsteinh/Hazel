#include "Renderer2D.h"

#include "Hazel/Textures/TextureBuilder.h"

namespace Hazel
{
	Renderer2D::Renderer2D(GraphicsContext &graphicsContext, const BatchInfo &info)
		: info(info),
		batchRenderer(graphicsContext, info)
	{
	}

	void Renderer2D::OnEvent(Event &e)
	{
		e.Dispatch([&](WindowResizeEvent &e)
		{
			batchRenderer.SetViewport({0.0f, e.GetWidth(), 0.0f, e.GetHeight()});
		});
	}

	void Renderer2D::BeginScene(const glm::mat4 &viewProjection)
	{
		batchRenderer.BeginScene(viewProjection);
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