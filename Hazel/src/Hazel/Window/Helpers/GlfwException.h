#pragma once

#include "Hazel/Exceptions/Exception.h"

namespace Hazel
{
	class GlfwException : public Exception
	{
	public:
		GlfwException(const std::string &description)
			: Exception(description)
		{
		}
	};
}