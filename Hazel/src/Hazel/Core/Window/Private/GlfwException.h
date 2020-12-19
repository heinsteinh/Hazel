#pragma once

#include "Hazel/Core/Exceptions/Exception.h"

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