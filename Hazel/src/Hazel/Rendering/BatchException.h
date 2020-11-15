#pragma once

#include "Hazel/Exceptions/Exception.h"

namespace Hazel
{
	class BatchException : public Exception
	{
	public:
		inline BatchException(const std::string &description)
			: Exception(description)
		{
		}
	};
}