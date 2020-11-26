#pragma once

#include "Exception.h"

namespace Hazel
{
	class AssertionException : public Exception
	{
	public:
		AssertionException(const std::string &description)
			: Exception(description)
		{
		}
	};
}

#ifdef HZ_DEBUG
#define HZ_ASSERT(expression, description) if (!(expression)) throw Hazel::AssertionException((description));
#else
#define HZ_ASSERT(expression, description)
#endif