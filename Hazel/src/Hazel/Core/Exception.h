#pragma once

namespace Hazel
{
	class Exception : public std::exception
	{
	public:
		virtual const std::string &GetDescription() const = 0;

		inline virtual const char *what() const override
		{
			return GetDescription().c_str();
		}
	};
}