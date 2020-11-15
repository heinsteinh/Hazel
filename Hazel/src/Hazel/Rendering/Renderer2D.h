#pragma once

#include "RendererStatistics.h"
#include "Hazel/Camera/OrthographicCamera.h"
#include "Hazel/Rendering/DefaultShader.h"
#include "Batch.h"
#include "BatchException.h"

namespace Hazel
{
	class Renderer2D
	{
	private:
		RendererInfo info;
		Batch batch;
		DefaultShader shader;
		RendererStatistics statistics;

	public:
		Renderer2D(const RendererInfo &info);

		void BeginScene(const OrthographicCamera &camera);
		void Render(const DrawData &drawData);
		void EndScene();

		constexpr const RendererInfo &GetBatchInfo() const
		{
			return info;
		}

		constexpr const RendererStatistics &GetStatistics() const
		{
			return statistics;
		}
	};
}