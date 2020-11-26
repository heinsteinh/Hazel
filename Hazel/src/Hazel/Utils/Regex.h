#pragma once

#include "RegexMatch.h"

namespace Hazel
{
	class Regex
	{
	private:
		std::regex pattern;

	public:
		Regex(const std::string &pattern)
			: pattern(pattern, std::regex::optimize)
		{
		}

		RegexMatch FindAll(const std::string &source) const
		{
			return {source, pattern};
		}
	};
}