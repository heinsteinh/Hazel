#pragma once

#include <string>
#include <optional>

#include "Hazel/Core/Utils/EnumMap.h"
#include "Hazel/Rendering/Mesh/VertexLayout.h"
#include "ShaderType.h"
#include "ShaderProperties.h"

namespace Hazel
{
	struct ShaderInfo
	{
		std::string Name;
		std::string Filename;
		VertexLayout UniformLayout;
		VertexLayout InputLayout;
		ShaderProperties Properties;
		EnumMap<ShaderType, std::string> Sources;

		bool IsValid() const
		{
			return !Sources[ShaderType::Vertex].empty() && !Sources[ShaderType::Fragment].empty();
		}
	};
}