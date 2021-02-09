#pragma once

#include "Hazel/Core/FileSystem/Filename.h"
#include "Hazel/Rendering/GraphicsContext/GraphicsContext.h"
#include "Hazel/Rendering/Glsl/GlslParser.h"

namespace Hazel
{
	class ShaderFactory
	{
	public:
		static std::shared_ptr<Shader> CreateShaderFromFile(GraphicsContext &graphicsContext, const std::string &filename)
		{
			return nullptr;
		}
	};
}