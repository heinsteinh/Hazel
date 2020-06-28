#pragma once

#include "Hazel/Events/Input/InputEvent.h"

namespace Hazel
{
	class MouseEvent : public InputEvent
	{
	protected:
		virtual void DispatchInputEvent(EventListener &listener) override;

		virtual void DispatchMouseEvent(EventListener &listener) = 0;
	};
}