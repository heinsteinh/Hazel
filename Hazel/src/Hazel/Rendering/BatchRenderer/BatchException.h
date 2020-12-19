#pragma once

#include "Hazel/Core/Exceptions/Exception.h"

namespace Hazel
{
	class BatchException : public Exception
	{
	public:
		BatchException(const std::string &description)
			: Exception(description)
		{
		}
	};
}