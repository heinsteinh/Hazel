#pragma once

#include "Hazel/BatchRendering/BatchRenderer.h"
#include "Hazel/Events/WindowResizeEvent.h"

namespace Hazel
{
	class Renderer2D
	{
	private:
		BatchRenderer batchRenderer;

	public:
		Renderer2D(GraphicsContext &graphicsContext, const BatchInfo &info);

		void BeginScene(const glm::mat4 &viewProjection);
		void Render(const DrawData &drawData);
		void EndScene();

		const RendererStatistics &GetStatistics() const
		{
			return batchRenderer.GetStatistics();
		}
	};
}