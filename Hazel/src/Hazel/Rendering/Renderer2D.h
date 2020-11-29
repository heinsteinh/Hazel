#pragma once

#include "RendererInfo.h"
#include "RendererStatistics.h"
#include "Hazel/Camera/OrthographicCamera.h"
#include "Hazel/BatchRendering/BatchRenderer.h"
#include "Hazel/Events/WindowResizeEvent.h"

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

		void OnEvent(Event &e);
		void BeginScene(const OrthographicCamera &camera);
		void Render(const DrawData &drawData);
		void EndScene();

		const RendererInfo &GetInfo() const
		{
			return info;
		}

		const RendererStatistics &GetStatistics() const
		{
			return batchRenderer.GetStatistics();
		}
	};
}