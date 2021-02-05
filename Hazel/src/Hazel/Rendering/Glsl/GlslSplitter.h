#pragma once

#include "spdlog/fmt/fmt.h"

#include "Hazel/Core/Utils/Regex.h"
#include "Hazel/Core/Utils/EnumMap.h"
#include "Hazel/Rendering/Shaders/ShaderTypeName.h"
#include "Hazel/Rendering/Shaders/ShaderCompilationException.h"

namespace Hazel
{
	class GlslSplitter
	{
	private:
		static inline const Regex typePattern = R"(##\s*(\w*))";

	public:
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
				sources[type] = first == last ? previous->suffix().str() : first->prefix().str();
			}
			return sources;
		}
	};
}