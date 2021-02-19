#include "Renderer.h"

#include "Private/RendererShader.h"
#include "Private/RendererDrawCall.h"
#include "Private/RendererSubmission.h"
#include "Private/RenderCommandSorter.h"

namespace Hazel
{
	Renderer::Renderer(const RendererInfo &info)
		: context(info)
	{
	}

	void Renderer::BeginScene(const Camera &camera, const std::shared_ptr<Framebuffer> &framebuffer)
	{
		context.Statistics.Reset();
		context.Command.Framebuffer = framebuffer;
		RendererShader::UpdateCamera(context, camera);
	}

	void Renderer::EndScene()
	{
		RenderCommandSorter::SortRenderQueue(context);
		for (const auto &command : context.RenderQueue)
		{
			RendererSubmission::Submit(context, command);
		}
		RendererDrawCall::Flush(context);
		context.RenderQueue.Clear();
	}
}