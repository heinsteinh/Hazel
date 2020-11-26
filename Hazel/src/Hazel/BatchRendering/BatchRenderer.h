#pragma once

#include "Batch.h"
#include "BatchException.h"
#include "Hazel/Rendering/RendererStatistics.h"

namespace Hazel
{
	class BatchRenderer
	{
	private:
		GraphicsContext *graphicsContext = nullptr;
		Batch batch;
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