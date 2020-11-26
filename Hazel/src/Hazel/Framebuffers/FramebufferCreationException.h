#pragma once

#include "Hazel/Exceptions/Exception.h"

namespace Hazel
{
	class FramebufferCreationException : public Exception
	{
	public:
		FramebufferCreationException(const std::string &description)
			: Exception(description)
		{
		}
	};
}