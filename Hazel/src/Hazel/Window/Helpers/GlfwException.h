#pragma once

#include "Hazel/Core/Exception.h"

namespace Hazel
{
	class GlfwException : public Exception
	{
	private:
		std::string description;

	public:
		inline GlfwException(const std::string &description)
			: description(description)
		{
		}

		inline virtual const std::string &GetDescription() const override
		{
			return description;
		}
	};
}