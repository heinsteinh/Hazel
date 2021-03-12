#pragma once

#include "Hazel/Rendering/Renderer/Renderer.h"

namespace Hazel
{
	class Renderer2D
	{
	private:
		Renderer renderer;
		const std::shared_ptr<Mesh> squareMesh;
		const std::shared_ptr<Shader> defaultShader;

	public:
		Renderer2D(const RendererInfo &info);

		void BeginScene(const Camera &camera)
		{
			renderer.BeginScene(camera);
		}

		RenderCommand &AddRenderCommand()
		{
			return renderer.AddRenderCommand();
		}
		void EndScene()
		{
			renderer.EndScene();
		}

		const std::shared_ptr<Mesh> &GetSquareMesh() const
		{
			return squareMesh;
		}

		const std::shared_ptr<Shader> &GetDefaultShader() const
		{
			return defaultShader;
		}

		const RendererStatistics &GetStatistics() const
		{
			return renderer.GetStatistics();
		}

		void SetFramebuffer(const std::shared_ptr<Framebuffer> &framebuffer)
		{
			renderer.SetFramebuffer(framebuffer);
		}
	};
}