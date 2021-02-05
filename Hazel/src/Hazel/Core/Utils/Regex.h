#pragma once

#include <string>
#include <regex>

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

		std::sregex_iterator Begin(const std::string &source) const
		{
			return {source.begin(), source.end(), pattern};
		}

		std::sregex_iterator End() const
		{
			return {};
		}

		bool Match(const std::string &source) const
		{
			return std::regex_match(source, pattern);
		}

		std::smatch Search(const std::string &source) const
		{
			std::smatch match;
			std::regex_search(source, match, pattern);
			return match;
		}

		template<typename FunctorType>
		void ForEachMatch(const std::string &source, FunctorType functor) const
		{
			std::sregex_iterator last;
			for (auto i = GetIterator(source); i != last; ++i)
			{
				functor(*i);
			}
		}
	};
}