#pragma once

#include "Hazel/Rendering/Renderer/Renderer.h"

namespace Hazel
{
	class Renderer2D
	{
	private:
		Renderer renderer;
		const std::shared_ptr<const Mesh> squareMesh;
		const std::shared_ptr<MaterialShader> defaultShader;

	public:
		Renderer2D(const RendererInfo &info);

		void BeginScene(const Camera &camera);
		void Submit(const RenderCommand &renderCommand);
		void EndScene();

		const Mesh &GetSquareMesh() const
		{
			return *squareMesh;
		}

		const std::shared_ptr<MaterialShader> &GetDefaultShader() const
		{
			return defaultShader;
		}

		const RendererStatistics &GetStatistics() const
		{
			return renderer.GetStatistics();
		}
	};
}