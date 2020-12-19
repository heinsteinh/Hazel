#pragma once

#include "Hazel/Rendering/GraphicsContext/GraphicsContext.h"

namespace Hazel
{
	class BatchShader
	{
	private:
		std::shared_ptr<Shader> shader;

	public:
		BatchShader(GraphicsContext &graphics)
			: shader(graphics.CreateShader(ShaderInfo::FromFiles({
			{ShaderType::Vertex, "C:\\Users\\christian\\source\\repos\\Hazel\\Hazel\\assets\\shaders\\BatchShader.vert"},
			{ShaderType::Pixel, "C:\\Users\\christian\\source\\repos\\Hazel\\Hazel\\assets\\shaders\\BatchShader.frag"}})))
		{
		}

		operator Shader *() const
		{
			return shader.get();
		}
	};
}