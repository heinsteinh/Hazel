#pragma once

#include "RendererInfo.h"
#include "RendererStatistics.h"
#include "Hazel/Camera/OrthographicCamera.h"
#include "Hazel/BatchRendering/Batch.h"
#include "Hazel/BatchRendering/BatchException.h"

namespace Hazel
{
	class Renderer2D
	{
	private:
		RendererInfo info;
		Batch batch;
		RendererStatistics statistics;

		static BatchInfo GetBatchInfo(const RendererInfo &rendererInfo);

	public:
		Renderer2D(const RendererInfo &info);

		void BeginScene(const OrthographicCamera &camera);
		void Render(const DrawData &drawData);
		void EndScene();

		constexpr const RendererInfo &GetInfo() const
		{
			return info;
		}

		constexpr const RendererStatistics &GetStatistics() const
		{
			return statistics;
		}
	};
}