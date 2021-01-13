#pragma once

#include "Hazel/Core/Exceptions/Exception.h"

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