#pragma once

#include "../Key.h"

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
			auto i = mapping.find(key);
			return i == mapping.end() ? Key::Invalid : i->second;
		}

		inline int GetNativeKey(Key key) const
		{
			auto i = reversedMapping.find(key);
			return i == reversedMapping.end() ? 0 : i->second;
		}

		inline auto begin() const
		{
			return mapping.begin();
		}

		inline auto end() const
		{
			return mapping.end();
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