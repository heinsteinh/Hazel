#pragma once

#include "BaseKeyEvent.h"

namespace Hazel
{
	class KeyPressEvent : public BaseKeyEvent
	{
	private:
		int repeatCount;

	public:
		constexpr KeyPressEvent(Key key, int repeatCount)
			: BaseKeyEvent(key),
			repeatCount(repeatCount)
		{
		}

		constexpr int GetRepeatCount() const
		{
			return repeatCount;
		}

		virtual std::string ToString() const override;

	protected:
		virtual void DispatchKeyEvent(EventListener &listener) override;
	};
}