#pragma once

namespace Hazel
{
	enum class KeyModifier
	{
		None = 0,
		Shift = 1,
		Ctrl = 2,
		Alt = 4,
		Super = 8,
		CapsLock = 16,
		NumLock = 32
	};

	constexpr KeyModifier operator|(KeyModifier left, KeyModifier right)
	{
		return static_cast<KeyModifier>(static_cast<int>(left) | static_cast<int>(right));
	}

	constexpr bool operator&(KeyModifier left, KeyModifier right)
	{
		return static_cast<int>(left) & static_cast<int>(right);
	}
}