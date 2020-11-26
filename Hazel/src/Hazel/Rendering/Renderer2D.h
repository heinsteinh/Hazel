#pragma once

#include "RendererInfo.h"
#include "RendererStatistics.h"
#include "Hazel/Camera/OrthographicCamera.h"
#include "Hazel/BatchRendering/BatchRenderer.h"

namespace Hazel
{
	class Renderer2D
	{
	private:
		RendererInfo info;
		BatchRenderer batchRenderer;

		static BatchInfo GetBatchInfo(const RendererInfo &rendererInfo);

	public:
		Renderer2D(const RendererInfo &info);

		void BeginScene(const OrthographicCamera &camera);
		void Render(const DrawData &drawData);
		void EndScene();

		inline const RendererInfo &GetInfo() const
		{
			return info;
		}

		inline const RendererStatistics &GetStatistics() const
		{
			return batchRenderer.GetStatistics();
		}
	};
}