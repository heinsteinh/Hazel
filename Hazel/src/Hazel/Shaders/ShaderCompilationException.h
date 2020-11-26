#pragma once

#include "Hazel/Exceptions/Exception.h"
#include "Hazel/Shaders/ShaderTypeName.h"

namespace Hazel
{
	class ShaderCompilationException : public Exception
	{
	public:
		ShaderCompilationException(const std::string &description)
			: Exception(description)
		{
		}
	};
}