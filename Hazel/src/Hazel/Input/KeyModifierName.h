#pragma once

#include "spdlog/fmt/ostr.h"

#include "KeyModifier.h"

namespace Hazel
{
	class KeyModifierName
	{
	public:
		static inline const std::string None = "None";
		static inline const std::string Shift = "Shift";
		static inline const std::string Ctrl = "Ctrl";
		static inline const std::string Alt = "Alt";
		static inline const std::string Super = "Super";
		static inline const std::string CapsLock = "CapsLock";
		static inline const std::string NumLock = "NumLock";

		static inline const std::string &GetKeyModifierName(KeyModifier button)
		{
			switch (button)
			{
			case KeyModifier::Shift:
				return Shift;
			case KeyModifier::Ctrl:
				return Ctrl;
			case KeyModifier::Alt:
				return Alt;
			case KeyModifier::Super:
				return Super;
			case KeyModifier::CapsLock:
				return CapsLock;
			case KeyModifier::NumLock:
				return NumLock;
			}
			return None;
		}

		KeyModifierName() = delete;
	};
}

inline std::ostream &operator<<(std::ostream &stream, Hazel::KeyModifier modifier)
{
	return stream << Hazel::KeyModifierName::GetKeyModifierName(modifier);
}