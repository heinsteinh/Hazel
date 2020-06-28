#pragma once

#include "KeyEvent.h"
#include "Hazel/Input/Key.h"

namespace Hazel
{
	class BaseKeyEvent : public KeyEvent
	{
	private:
		Key key;

	public:
		constexpr BaseKeyEvent(Key key)
			: key(key)
		{
		}

		constexpr Key GetKey() const
		{
			return key;
		}

		inline virtual std::string ToString() const override
		{
			return (std::ostringstream()
				<< GetName() << ": " << static_cast<int>(key))
				.str();
		}
	};
}