#pragma once

#include "Key.h"

namespace Hazel
{
	class KeyMap
	{
	private:
		std::unordered_map<int, Key> mapping;
		std::unordered_map<Key, int> reversedMapping;

	public:
		inline KeyMap(std::initializer_list<std::pair<const int, Key>> mapping)
			: mapping(mapping)
		{
			for (auto [key, value] : mapping)
			{
				reversedMapping[value] = key;
			}
		}

		inline Key GetHazelKey(int key) const
		{
			auto nativeHazel = mapping.find(key);
			return nativeHazel == mapping.end() ? Key::Invalid : nativeHazel->second;
		}

		inline int GetNativeKey(Key key) const
		{
			auto hazelNative = reversedMapping.find(key);
			return hazelNative == reversedMapping.end() ? 0 : hazelNative->second;
		}

		inline Key operator[](int key) const
		{
			return GetHazelKey(key);
		}

		inline int operator[](Key key) const
		{
			return GetNativeKey(key);
		}
	};
}