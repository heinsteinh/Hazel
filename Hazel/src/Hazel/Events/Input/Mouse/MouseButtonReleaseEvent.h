#pragma once

#include "MouseButtonEvent.h"

namespace Hazel
{
	class MouseButtonReleaseEvent : public MouseButtonEvent
	{
	public:
		constexpr MouseButtonReleaseEvent(MouseButton button)
			: MouseButtonEvent(button)
		{
		}

	protected:
		virtual void DispatchMouseButtonEvent(EventListener &listener) override;
	};
}