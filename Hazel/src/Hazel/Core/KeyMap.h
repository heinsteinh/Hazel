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
        KeyMap(std::initializer_list<std::pair<const int, Key>> mapping);

        Key GetHazelKey(int key) const;
        int GetNativeKey(Key key) const;

        inline Key operator[](int key) const
        {
            return GetHazelKey(key);
        }

        inline int operator[](Key key) const
        {
            return GetNativeKey(key);
        }

    private:
        void Init();
    };
}