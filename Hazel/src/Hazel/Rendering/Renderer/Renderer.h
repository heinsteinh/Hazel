#pragma once

#include "Hazel/Core/Camera/Camera.h"
#include "Hazel/Rendering/Framebuffers/Framebuffer.h"
#include "RendererInfo.h"
#include "RendererStatistics.h"
#include "RendererException.h"
#include "RenderCommand.h"
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
		void EndScene();

		const RendererStatistics &GetStatistics() const
		{
			return context.Statistics;
		}

		template<typename ...Args>
		RenderCommand &AddRenderCommand(Args &&...args)
		{
			return context.RenderQueue.Emplace(std::forward<Args>(args)...);
		}
	};
}