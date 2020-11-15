#pragma once

#include "spdlog/fmt/ostr.h"

#include "Key.h"

namespace Hazel
{
	class KeyName
	{
	private:
		static inline std::mutex mutex;
		static inline std::unordered_map<Key, std::string> keyNames;
		static inline std::unordered_map<int, std::string> scancodeNames;

	public:
		static const std::string &GetKeyName(Key key);
		static const std::string &GetScancodeName(int scancode);
	};
}

inline std::ostream &operator<<(std::ostream &stream, Hazel::Key key)
{
	return stream << Hazel::KeyName::GetKeyName(key);
}