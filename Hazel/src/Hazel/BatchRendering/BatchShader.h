#pragma once

#include "Hazel/GraphicsContext/GraphicsContext.h"

namespace Hazel
{
	class BatchShader
	{
	private:
		std::shared_ptr<Shader> shader;

	public:
		inline BatchShader(GraphicsContext &graphics)
			: shader(graphics.CreateShader(ShaderInfo::FromFiles({
			{ShaderType::Vertex, R"(C:\Users\christian\source\repos\Hazel\Hazel\assets\shaders\BatchShader.vert)"},
			{ShaderType::Pixel, R"(C:\Users\christian\source\repos\Hazel\Hazel\assets\shaders\BatchShader.frag)"}})))
		{
		}

		constexpr operator const std::shared_ptr<Shader> &() const
		{
			return shader;
		}
	};
}