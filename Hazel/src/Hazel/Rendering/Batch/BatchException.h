#pragma once

#include "Hazel/Core/Exception.h"

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