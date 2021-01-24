#pragma once

#include <string>
#include <optional>

#include "Hazel/Rendering/Mesh/VertexLayout.h"
#include "ShaderUniformMap.h"

namespace Hazel
{
	struct ShaderInfo
	{
		VertexLayout UniformLayout;
		ShaderUniformMap UniformMap;
		VertexLayout InputLayout;
		std::string VertexSource;
		std::string PixelSource;
	};
}