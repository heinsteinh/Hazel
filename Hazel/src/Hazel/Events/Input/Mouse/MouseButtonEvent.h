#pragma once

#include "MouseEvent.h"
#include "Hazel/Input/MouseButton.h"

namespace Hazel
{
	class MouseButtonEvent : public MouseEvent
	{
	private:
		MouseButton button;

	public:
		constexpr MouseButtonEvent(MouseButton button)
			: button(button)
		{
		}

		constexpr MouseButton GetButton() const
		{
			return button;
		}

		virtual std::string ToString() const override;

	protected:
		virtual void DispatchMouseEvent(EventListener &listener) override;

		virtual void DispatchMouseButtonEvent(EventListener &listener) = 0;
	};
}