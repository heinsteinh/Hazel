#pragma once

#include "Hazel/Rendering/Shaders/ShaderInfo.h"

namespace Hazel
{
	class DefaultShaderInfo
	{
	private:
		static inline const ShaderInfo info = ShaderInfo::FromFiles({
			{ShaderType::Vertex, R"(C:\Users\christian\source\repos\Hazel\Hazel\assets\shaders\DefaultShader.vert)"},
			{ShaderType::Pixel, R"(C:\Users\christian\source\repos\Hazel\Hazel\assets\shaders\DefaultShader.frag)"}});

	public:
		static inline const ShaderInfo &Get()
		{
			return info;
		}

		DefaultShaderInfo() = delete;
	};
}