#pragma once

#include "KeyEvent.h"

namespace Hazel
{
	class KeyTypeEvent : public KeyEvent
	{
	private:
		int key;

	public:
		constexpr KeyTypeEvent(int key)
			: key(key)
		{
		}

		constexpr int GetKey() const
		{
			return key;
		}

		virtual std::string ToString() const override;

	protected:
		virtual void DispatchKeyEvent(EventListener &listener) override;
	};
}