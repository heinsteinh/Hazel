#pragma once

#include "spdlog/fmt/ostr.h"

#include "Key.h"

namespace Hazel
{
	class KeyName
	{
	public:
		static const char *GetKeyName(Key key);
		static const char *GetScancodeName(int scancode);
	};
}

inline std::ostream &operator<<(std::ostream &stream, Hazel::Key key)
{
	return stream << Hazel::KeyName::GetKeyName(key);
}