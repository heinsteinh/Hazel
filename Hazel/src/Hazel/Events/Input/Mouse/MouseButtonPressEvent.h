#pragma once

#include "MouseButtonEvent.h"

namespace Hazel
{
	class MouseButtonPressEvent : public MouseButtonEvent
	{
	public:
		constexpr MouseButtonPressEvent(MouseButton button)
			: MouseButtonEvent(button)
		{
		}

	protected:
		virtual void DispatchMouseButtonEvent(EventListener &listener) override;
	};
}