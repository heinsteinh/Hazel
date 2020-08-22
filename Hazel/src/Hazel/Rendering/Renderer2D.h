#pragma once

#include "RendererStatistics.h"
#include "Hazel/Core/Context.h"
#include "Hazel/Camera/OrthographicCamera.h"
#include "Hazel/Rendering/DefaultShader.h"
#include "Batch/Batch.h"
#include "Batch/BatchException.h"

namespace Hazel
{
	class Renderer2D
	{
	private:
		Drawer &drawer;
		DefaultShader shader;
		BatchInfo batchInfo;
		Batch batch;
		RendererStatistics statistics;

	public:
		Renderer2D(const Context &context);

		void Init(const BatchInfo &info);
		void BeginScene(const OrthographicCamera &camera);
		void Draw(const DrawData &drawData);
		void EndScene();

		constexpr const BatchInfo &GetBatchInfo() const
		{
			return batchInfo;
		}

		constexpr const RendererStatistics &GetStatistics() const
		{
			return statistics;
		}
	};
}