#pragma once

#include "BaseKeyEvent.h"

namespace Hazel
{
	class KeyReleaseEvent : public BaseKeyEvent
	{
	public:
		constexpr KeyReleaseEvent(Key key)
			: BaseKeyEvent(key)
		{
		}

	protected:
		virtual void DispatchKeyEvent(EventListener &listener) override;
	};
}