#pragma once

#include "Hazel/Core/Exception.h"
#include "Hazel/Shaders/ShaderTypeName.h"

namespace Hazel
{
	class ShaderCompilationException : public Exception
	{
	public:
		inline ShaderCompilationException(ShaderType type, const std::string &infoLog)
			: Exception(fmt::format("Compilation of {} shader failed: {}.", ShaderTypeName::GetName(type), infoLog))
		{
		}

		inline ShaderCompilationException(const std::string &description)
			: Exception(description)
		{
		}
	};
}