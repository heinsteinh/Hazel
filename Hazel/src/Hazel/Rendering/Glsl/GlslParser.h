#pragma once

#include "Hazel/Core/Utils/Regex.h"
#include "Hazel/Core/FileSystem/FileReader.h"
#include "Hazel/Rendering/Shaders/ShaderInfo.h"
#include "Hazel/Rendering/Shaders/ShaderTypeName.h"
#include "Hazel/Rendering/Shaders/ShaderCompilationException.h"

namespace Hazel
{
	class GlslParser
	{
	private:
		static inline const Regex typePattern = R"(##\s*(\w*))";
		static inline const Regex uniformBlockPattern = R"((?s)layout\s*\(binding\s*=\s*(\d+)\)\s*uniform\s*\w+\s*\{\s*(.*?)\s*\})";
		static inline const Regex uniformPattern = R"((\w+) (\w+);)";
		static inline const Regex inputPattern = R"(layout\s*\(location\s*=\s*(\d+)\)\s*in\s*(\w+)\s*(\w+);)";

	public:
		static ShaderInfo Parse(const std::string &filename)
		{
			ShaderInfo info;
			info.Sources = SplitShaders(FileReader::ReadAll(filename));
		}

		static EnumMap<ShaderType, std::string> SplitShaders(const std::string &source)
		{
			return SplitShaders(typePattern.Begin(source), typePattern.End());
		}

		static EnumMap<ShaderType, std::string> SplitShaders(std::sregex_iterator first, std::sregex_iterator last)
		{
			EnumMap<ShaderType, std::string> sources;
			while (first != last)
			{
				auto name = (*first)[1].str();
				auto type = ShaderTypeName::GetType(name);
				if (type == ShaderType::Unknown)
				{
					throw ShaderCompilationException(fmt::format("Invalid shader type: {}", name));
				}
				auto previous = first++;
				sources[type] = first == last
					? previous->suffix().str()
					: first->prefix().str();
			}
			return sources;
		}

		static VertexLayout GetInputLayout(const std::string &vertexSource)
		{
			inputPattern.ForEachMatch(vertexSource, [](const auto &match)
			{
			});
		}
	};
}