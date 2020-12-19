#pragma once

#include "Hazel/Core/Exceptions/Exception.h"
#include "Hazel/Rendering/Shaders/ShaderTypeName.h"

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