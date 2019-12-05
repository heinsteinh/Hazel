#pragma once

#include <unordered_map>

#include "Hazel/Core/Key.h"

namespace Hazel
{
    class KeyMap
    {
    private:
        std::unordered_map<int, Key> mapping;
        std::unordered_map<Key, int> reversedMapping;

    public:
        KeyMap(std::initializer_list<std::pair<const int, Key>> mapping)
            : mapping(mapping)
        {
            Init();
        }

        inline Key GetHazelKey(int key) const
        {
            auto result = mapping.find(key);
            return result == mapping.end()
                ? Key::Invalid
                : result->second;
        }

        inline int GetNativeKey(Key key) const
        {
            auto result = reversedMapping.find(key);
            return result == reversedMapping.end()
                ? 0
                : result->second;
        }

        inline Key operator[](int key) const
        {
            return GetHazelKey(key);
        }

        inline int operator[](Key key) const
        {
            return GetNativeKey(key);
        }

    private:
        void Init()
        {
            for (const auto keyValue : mapping)
            {
                reversedMapping[keyValue.second] = keyValue.first;
            }
        }
    };
}