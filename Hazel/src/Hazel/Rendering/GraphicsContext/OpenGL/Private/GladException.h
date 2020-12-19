#pragma once

#include "Hazel/Core/Exceptions/Exception.h"

namespace Hazel
{
	class GladException : public Exception
	{
	public:
		GladException(const std::string &description)
			: Exception(description)
		{
		}
	};
}