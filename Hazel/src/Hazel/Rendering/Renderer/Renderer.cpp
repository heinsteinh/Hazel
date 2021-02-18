#include "Renderer.h"

#include "Hazel/Core/Exceptions/AssertionException.h"
#include "Private/RendererShader.h"
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
		RendererShader::UpdateCamera(context, camera);
	}

	void Renderer::Submit(const RenderCommand &command)
	{
		HZ_ASSERT(command.IsValid(), "Render command needs at least a mesh and a shader");
		context.RenderQueue.Add(command);
	}

	void Renderer::EndScene()
	{
		context.RenderQueue.Sort();
		for (const auto &command : context.RenderQueue)
		{
			RendererSubmission::Submit(context, command);
		}
		RendererDrawCall::Flush(context);
		context.RenderQueue.Clear();
	}
}