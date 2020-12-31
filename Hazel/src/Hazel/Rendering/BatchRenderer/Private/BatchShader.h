#pragma once

#include "Hazel/Rendering/GraphicsContext/GraphicsContext.h"

namespace Hazel
{
	class BatchShader
	{
	public:
		static std::shared_ptr<Shader> CreateShader(GraphicsContext &graphicsContext)
		{
			return graphicsContext.CreateShader(ShaderInfo::FromFiles({
				{ShaderType::Vertex, "C:\\Users\\christian\\source\\repos\\Hazel\\Hazel\\assets\\shaders\\BatchShader.vert"},
				{ShaderType::Pixel, "C:\\Users\\christian\\source\\repos\\Hazel\\Hazel\\assets\\shaders\\BatchShader.frag"}}));
		}
	};
}