#pragma once

#include "Hazel/Events/Input/InputEvent.h"

namespace Hazel
{
	class KeyEvent : public InputEvent
	{
	protected:
		virtual void DispatchInputEvent(EventListener &listener) override;

		virtual void DispatchKeyEvent(EventListener &listener) = 0;
	};
}