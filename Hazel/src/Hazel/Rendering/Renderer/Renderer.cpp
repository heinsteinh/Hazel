#include "Renderer.h"

#include "Private/RendererPrivate.h"
#include "Private/RendererShader.h"
#include "Private/RendererDrawCall.h"
#include "Private/RendererSubmission.h"
#include "Private/RenderCommandSorter.h"

namespace Hazel
{
	Renderer::Renderer(const RendererInfo &info)
		: renderer(std::make_unique<RendererPrivate>(info))
	{
	}

	Renderer::~Renderer()
	{
	}

	void Renderer::BeginScene(const Camera &camera)
	{
		renderer->Statistics.Reset();
		RendererShader::UpdateCamera(*renderer, camera);
	}

	RenderCommand &Renderer::AddRenderCommand()
	{
		return renderer->RenderQueue.Add();
	}

	void Renderer::EndScene()
	{
		RenderCommandSorter::SortRenderQueue(*renderer);
		for (const auto &command : renderer->RenderQueue)
		{
			RendererSubmission::Submit(*renderer, command);
		}
		RendererDrawCall::Flush(*renderer);
		renderer->RenderQueue.Clear();
	}

	const RendererStatistics &Renderer::GetStatistics() const
	{
		return renderer->Statistics;
	}

	void Renderer::SetFramebuffer(const std::shared_ptr<Framebuffer> &framebuffer)
	{
		renderer->Command.Framebuffer = framebuffer;
	}
}