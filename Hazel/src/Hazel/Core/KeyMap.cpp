#include "KeyMap.h"

namespace Hazel
{
    KeyMap::KeyMap(std::initializer_list<std::pair<const int, Key>> mapping)
        : mapping(mapping)
    {
        Init();
    }

    Key KeyMap::GetHazelKey(int key) const
    {
        auto result = mapping.find(key);
        return result == mapping.end()
            ? Key::Invalid
            : result->second;
    }

    int KeyMap::GetNativeKey(Key key) const
    {
        auto result = reversedMapping.find(key);
        return result == reversedMapping.end()
            ? 0
            : result->second;
    }

    void KeyMap::Init()
    {
        for (const auto keyValue : mapping)
        {
            reversedMapping[keyValue.second] = keyValue.first;
        }
    }
}