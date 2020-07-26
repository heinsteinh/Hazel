#pragma once

#include "spdlog/fmt/ostr.h"

#include "ShaderType.h"

namespace Hazel
{
	class ShaderTypeName
	{
	private:
		static inline const std::string vertexName = "vertex";
		static inline const std::string pixelName = "pixel";
		static inline const std::string defaultName;

	public:
		static constexpr const std::string &GetName(ShaderType type)
		{
			switch (type)
			{
			case ShaderType::Vertex:
				return vertexName;
			case ShaderType::Pixel:
				return pixelName;
			}
			return defaultName;
		}

		ShaderTypeName() = delete;
	};
}

inline std::ostream &operator<<(std::ostream &stream, Hazel::ShaderType type)
{
	return stream << Hazel::ShaderTypeName::GetName(type);
}