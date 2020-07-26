#pragma once

#include "RegexMatch.h"

namespace Hazel
{
	class Regex
	{
	private:
		std::regex pattern;

	public:
		inline Regex(const std::string &pattern)
			: pattern(pattern, std::regex::optimize)
		{
		}

		inline RegexMatch FindAll(const std::string &source) const
		{
			return {source, pattern};
		}
	};
}