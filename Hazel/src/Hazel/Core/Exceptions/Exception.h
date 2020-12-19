#pragma once

#include <string>

namespace Hazel
{
	class Exception : public std::exception
	{
	private:
		std::string description;

	public:
		Exception(const std::string &description)
			: description(description)
		{
		}

		Exception(std::string &&description)
			: description(std::move(description))
		{
		}

		constexpr const std::string &GetDescription() const
		{
			return description;
		}

		virtual const char *what() const override
		{
			return description.c_str();
		}
	};
}