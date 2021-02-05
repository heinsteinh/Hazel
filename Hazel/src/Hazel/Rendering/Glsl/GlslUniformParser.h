#pragma once

#include "Hazel/Core/Utils/Regex.h"
#include "Hazel/Rendering/Mesh/VertexLayout.h"
#include "GlslInputParser.h"

namespace Hazel
{
	class GlslUniformParser
	{
	private:
		static inline const Regex uniformBlockPattern = R"((?s)layout\s*\(binding\s*=\s*(\d+)\)\s*uniform\s*\w+\s*\{\s*(.*?)\s*\})";
		static inline const Regex uniformPattern = R"((\w+) (\w+);)";
		static inline const Regex inputPattern = R"(layout\s*\(location\s*=\s*(\d+)\)\s*in\s*(\w+)\s*(\w+);)";

	public:
		static VertexLayout ParseUniformLayout(const std::string &vertexSource)
		{
		}
	};
}