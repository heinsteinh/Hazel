#pragma once

#include "Hazel/Rendering/RendererStatistics.h"
#include "Private/BatchContext.h"
#include "BatchException.h"

namespace Hazel
{
	class BatchRenderer
	{
	private:
		GraphicsContext *graphicsContext = nullptr;
		BatchContext batch;
		RendererStatistics statistics;

	public:
		BatchRenderer(GraphicsContext &graphicsContext, const BatchInfo &info);

		void BeginScene(const glm::mat4 &viewProjectionMatrix);
		void Render(const DrawData &drawData);
		void EndScene();

		const RendererStatistics &GetStatistics() const
		{
			return statistics;
		}
	};
}