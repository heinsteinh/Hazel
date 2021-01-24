#pragma once

#include "RendererInfo.h"
#include "RendererException.h"
#include "Private/RendererContext.h"

namespace Hazel
{
	class Renderer
	{
	private:
		RendererContext context;

	public:
		Renderer(const RendererInfo &info);

		void BeginScene(const Camera &camera, const std::shared_ptr<Framebuffer> &framebuffer = nullptr);
		void Submit(const RenderCommand &command);
		void EndScene();

		const RendererStatistics &GetStatistics() const
		{
			return context.Statistics;
		}
	};
}