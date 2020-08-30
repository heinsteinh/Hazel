#pragma once

#include "Hazel/Core/Exception.h"

namespace Hazel
{
	class FramebufferCreationException : public Exception
	{
	public:
		inline FramebufferCreationException(const std::string &description)
			: Exception(description)
		{
		}
	};
}