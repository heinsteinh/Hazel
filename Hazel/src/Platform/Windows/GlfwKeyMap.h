#pragma once

#include "Hazel/Core/KeyMap.h"

namespace Hazel
{
    class GlfwKeyMap
    {
    private:
        static const KeyMap keymap;

    public:
        GlfwKeyMap() = delete;

        static inline Key GetHazelKey(int key)
        {
            return keymap.GetHazelKey(key);
        }

        static inline int GetNativeKey(Key key)
        {
            return keymap.GetNativeKey(key);
        }
    };
}