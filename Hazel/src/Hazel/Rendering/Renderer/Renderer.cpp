#include "Renderer.h"

#include "Private/RendererShaderManager.h"
#include "Private/RendererDrawCall.h"
#include "Private/RendererSubmission.h"

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
		RendererShaderManager::UpdateCamera(context, camera);
	}

	void Renderer::Submit(const RenderCommand &command)
	{
		RendererSubmission::Submit(context, command);
	}

	void Renderer::EndScene()
	{
		RendererDrawCall::Flush(context);
	}
}