#pragma once

namespace Hazel
{
	struct Tag
	{
		std::string Name;

		Tag(const std::string &name)
			: Name(name)
		{
		}
	};
}