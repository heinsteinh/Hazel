#pragma once

#include "spdlog/fmt/ostr.h"
#include "glm/glm.hpp"

#include "Hazel/Core/Input/Key.h"
#include "Hazel/Core/Input/KeyModifier.h"
#include "Hazel/Core/Input/MouseButton.h"
#include "EventType.h"
#include "EventCategory.h"

namespace Hazel
{
	struct Event
	{
		EventType Type = EventType::Unknown;
		EventCategory Categories = EventCategory::None;
		bool Blocked = false;
		Key Key = Key::Invalid;
		int Scancode = 0;
		KeyModifier KeyModifiers = KeyModifier::None;
		int RepeatCount = 0;
		unsigned int Text = 0;
		MouseButton MouseButton = MouseButton::Invalid;
		glm::vec2 MousePosition{0.0f};
		glm::vec2 MouseScrollOffset{0.0f};
		glm::vec2 WindowSize{0.0f};
	};
}