#pragma once

#include "KeyEvent.h"

namespace Hazel
{
	class KeyTypeEvent : public KeyEvent
	{
	private:
		unsigned int key;

	public:
		constexpr KeyTypeEvent(unsigned int key)
			: key(key)
		{
		}

		constexpr unsigned int GetKey() const
		{
			return key;
		}

		virtual std::string ToString() const override;

	protected:
		virtual void DispatchKeyEvent(EventListener &listener) override;
	};
}