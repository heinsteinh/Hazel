#pragma once

#include "Hazel/Core/Exception.h"

namespace Hazel
{
	class BatchException : public Exception
	{
	private:
		std::string description;

	public:
		inline BatchException(const std::string &description)
			: description(description)
		{
		}

		inline virtual const std::string &GetDescription() const override
		{
			return description;
		}
	};
}