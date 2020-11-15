#pragma once

namespace Hazel
{
	class Exception : public std::exception
	{
	private:
		std::string description;

	public:
		inline Exception(const std::string &description)
			: description(description)
		{
		}

		inline Exception(std::string &&description)
			: description(std::move(description))
		{
		}

		constexpr const std::string &GetDescription() const
		{
			return description;
		}

		inline virtual const char *what() const override
		{
			return description.c_str();
		}
	};
}