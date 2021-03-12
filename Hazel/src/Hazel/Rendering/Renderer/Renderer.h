#pragma once

#include "Hazel/Core/Camera/Camera.h"
#include "Hazel/Rendering/Framebuffers/Framebuffer.h"
#include "RendererInfo.h"
#include "RendererStatistics.h"
#include "RendererException.h"
#include "RenderCommand.h"

namespace Hazel
{
	struct RendererPrivate;

	class Renderer
	{
	private:
		std::unique_ptr<RendererPrivate> renderer;

	public:
		Renderer(const RendererInfo &info);
		~Renderer();

		void BeginScene(const Camera &camera);
		RenderCommand &AddRenderCommand();
		void EndScene();
		const RendererStatistics &GetStatistics() const;
		void SetFramebuffer(const std::shared_ptr<Framebuffer> &framebuffer);
	};
}