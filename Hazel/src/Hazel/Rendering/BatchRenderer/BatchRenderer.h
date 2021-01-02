#pragma once

#include "glm/glm.hpp"

#include "Hazel/Rendering/Renderer2D/RendererStatistics.h"
#include "Hazel/Rendering/Renderer2D/DrawData.h"
#include "Hazel/Rendering/Renderer2D/RendererInfo.h"
#include "BatchException.h"
#include "Private/BatchContext.h"

namespace Hazel
{
	class BatchRenderer
	{
	private:
		GraphicsContext *graphicsContext = nullptr;
		BatchContext batch;
		RendererStatistics statistics;

	public:
		BatchRenderer(GraphicsContext &graphicsContext, const RendererInfo &info);

		void BeginScene(const glm::mat4 &viewProjectionMatrix);
		void Render(const DrawData &drawData);
		void EndScene();

		const RendererStatistics &GetStatistics() const
		{
			return statistics;
		}
	};
}