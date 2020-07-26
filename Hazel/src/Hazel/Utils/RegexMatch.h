#pragma once

namespace Hazel
{
	class RegexMatch
	{
	private:
		std::sregex_iterator first;
		std::sregex_iterator last;

	public:
		RegexMatch(const std::string &source, const std::regex &pattern)
			: first(source.begin(), source.end(), pattern)
		{
		}

		inline auto begin() const
		{
			return first;
		}

		inline auto end() const
		{
			return last;
		}
	};
}