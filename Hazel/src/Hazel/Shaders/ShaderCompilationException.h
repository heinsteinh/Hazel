#pragma once

#include "Hazel/Core/Exception.h"
#include "Hazel/Shaders/ShaderTypeName.h"

namespace Hazel
{
	class ShaderCompilationException : public Exception
	{
	public:
		inline ShaderCompilationException(ShaderType type, const std::string &infoLog)
			: Exception("Compilation of " + ShaderTypeName::GetName(type) + " shader failed: " + infoLog)
		{
		}

		inline ShaderCompilationException(const std::string &description)
			: Exception(description)
		{
		}
	};
}