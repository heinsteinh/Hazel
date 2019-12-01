#pragma once

#include "Hazel/Core/KeyMap.h"
#include "imgui.h"

namespace Hazel
{
    const KeyMap ImGuiKeyMap = {
        {ImGuiKey_Tab,          Key::Tab},
        {ImGuiKey_LeftArrow,    Key::Left},
        {ImGuiKey_RightArrow,   Key::Right},
        {ImGuiKey_UpArrow,      Key::Up},
        {ImGuiKey_DownArrow,    Key::Down},
        {ImGuiKey_PageUp,       Key::PageUp},
        {ImGuiKey_PageDown,     Key::PageDown},
        {ImGuiKey_Home,         Key::Home},
        {ImGuiKey_End,          Key::End},
        {ImGuiKey_Insert,       Key::Insert},
        {ImGuiKey_Delete,       Key::Delete},
        {ImGuiKey_Backspace,    Key::Backspace},
        {ImGuiKey_Space,        Key::Space},
        {ImGuiKey_Enter,        Key::Enter},
        {ImGuiKey_Escape,       Key::Escape}
    };
}