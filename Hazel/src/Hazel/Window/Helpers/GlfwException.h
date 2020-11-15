#pragma once

#include "Hazel/Exceptions/Exception.h"

namespace Hazel
{
	class GlfwException : public Exception
	{
	public:
		inline GlfwException(const std::string &description)
			: Exception(description)
		{
		}
	};
}