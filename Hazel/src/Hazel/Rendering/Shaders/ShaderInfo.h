#pragma once

#include "Hazel/Rendering/Shaders/ShaderType.h"

namespace Hazel
{
	struct ShaderInfo
	{
		std::string Name;
		std::unordered_map<ShaderType, std::string> Sources;
	};
}