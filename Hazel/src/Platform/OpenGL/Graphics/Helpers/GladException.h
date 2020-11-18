#pragma once

#include "Hazel/Exceptions/Exception.h"

namespace Hazel
{
	class GladException : public Exception
	{
	public:
		inline GladException(const std::string &description)
			: Exception(description)
		{
		}
	};
}