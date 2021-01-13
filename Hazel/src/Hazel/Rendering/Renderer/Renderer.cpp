#include "Renderer.h"

namespace Hazel
{
	Renderer::Renderer(const RendererInfo &info)
		: commandHandler(info)
	{
	}

	void Renderer::BeginScene(const Camera &camera)
	{
		commandHandler.SetCamera(camera);
	}

	void Renderer::Submit(const RenderCommand &renderCommand)
	{
		renderQueue.Add(renderCommand);
	}

	void Renderer::EndScene()
	{
		for (const auto &command : renderQueue)
		{
			commandHandler.Submit(command);
		}
		commandHandler.Flush();
		renderQueue.Clear();
	}
}