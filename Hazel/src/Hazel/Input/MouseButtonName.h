#pragma once

#include "spdlog/fmt/ostr.h"

#include "MouseButton.h"

namespace Hazel
{
	class MouseButtonName
	{
	public:
		static inline const std::string B1 = "MouseButton1";
		static inline const std::string B2 = "MouseButton2";
		static inline const std::string B3 = "MouseButton3";
		static inline const std::string B4 = "MouseButton4";
		static inline const std::string B5 = "MouseButton5";
		static inline const std::string B6 = "MouseButton6";
		static inline const std::string B7 = "MouseButton7";
		static inline const std::string B8 = "MouseButton8";
		static inline const std::string Invalid = "InvalidMouseButton";

		static const std::string &GetMouseButtonName(MouseButton button)
		{
			switch (button)
			{
			case MouseButton::B1:
				return B1;
			case MouseButton::B2:
				return B2;
			case MouseButton::B3:
				return B3;
			case MouseButton::B4:
				return B4;
			case MouseButton::B5:
				return B5;
			case MouseButton::B6:
				return B6;
			case MouseButton::B7:
				return B7;
			case MouseButton::B8:
				return B8;
			}
			return Invalid;
		}
	};
}

inline std::ostream &operator<<(std::ostream &stream, Hazel::MouseButton button)
{
	return stream << Hazel::MouseButtonName::GetMouseButtonName(button);
}