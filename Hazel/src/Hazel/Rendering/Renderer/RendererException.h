#pragma once

#include "Hazel/Core/Exceptions/Exception.h"

namespace Hazel
{
	class RendererException : public Exception
	{
	public:
		RendererException(const std::string &description)
			: Exception(description)
		{
		}
	};
}