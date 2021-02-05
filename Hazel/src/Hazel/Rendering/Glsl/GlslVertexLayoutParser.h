#pragma once

#include "spdlog/fmt/fmt.h"

#include "Hazel/Core/Utils/Regex.h"
#include "Hazel/Rendering/Mesh/VertexLayout.h"
#include "Hazel/Rendering/Shaders/ShaderCompilationException.h"
#include "GlslType.h"

namespace Hazel
{
	class GlslVertexLayoutParser
	{
	private:
		static inline const Regex uniformBlockPattern = R"((?s)layout\s*\(binding\s*=\s*(\d+)\)\s*uniform\s*\w+\s*\{\s*(.*?)\s*\})";
		static inline const Regex uniformPattern = R"((\w+) (\w+);)";
		static inline const Regex inputPattern = R"(layout\s*\(location\s*=\s*(\d+)\)\s*in\s*(\w+)\s*(\w+);)";

	public:
		static VertexLayout ParseUniform(const std::string &source)
		{
			return ParseVertexLayout(uniformPattern, uniformBlockPattern.Search(source).str());
		}

		static VertexLayout ParseInput(const std::string &source)
		{
			return ParseVertexLayout(inputPattern, source);
		}

	private:
		static VertexLayout ParseVertexLayout(const Regex &pattern, const std::string &source)
		{
			std::vector<VertexAttribute> attributes;
			pattern.ForEachMatch(source, [&](const auto &match)
			{
				auto name = match[1].str();
				auto type = GlslType::GetShaderDataType(name);
				if (type == ShaderDataType::Unknown)
				{
					throw ShaderCompilationException(fmt::format("Invalid data type: {}", name))
				}
				attributes.emplace_back(type);
			});
			return attributes;
		}
	};
}