#pragma once

#include "Hazel/Core/Exception.h"

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