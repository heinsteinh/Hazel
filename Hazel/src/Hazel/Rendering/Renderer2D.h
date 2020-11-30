#pragma once

#include "Hazel/BatchRendering/BatchRenderer.h"
#include "Hazel/Events/WindowResizeEvent.h"

namespace Hazel
{
	class Renderer2D
	{
	private:
		BatchInfo info;
		BatchRenderer batchRenderer;

	public:
		Renderer2D(GraphicsContext &graphicsContext, const BatchInfo &info);

		void OnEvent(Event &e);
		void BeginScene(const glm::mat4 &viewProjection);
		void Render(const DrawData &drawData);
		void EndScene();

		const BatchInfo &GetBatchInfo() const
		{
			return info;
		}

		const RendererStatistics &GetStatistics() const
		{
			return batchRenderer.GetStatistics();
		}
	};
}