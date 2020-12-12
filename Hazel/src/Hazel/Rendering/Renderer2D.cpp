#include "Renderer2D.h"

#include "Hazel/Textures/TextureBuilder.h"

namespace Hazel
{
	Renderer2D::Renderer2D(GraphicsContext &graphicsContext, const BatchInfo &info)
		: batchRenderer(graphicsContext, info)
	{
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