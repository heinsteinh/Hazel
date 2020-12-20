#pragma once

#include "Hazel/Core/Exceptions/Exception.h"

namespace Hazel
{
	class SceneParsingException : public Exception
	{
	public:
		SceneParsingException(const std::string &description)
			: Exception(description)
		{
		}
	};
}