#pragma once

#include "MouseEvent.h"

namespace Hazel
{
	class MouseMoveEvent : public MouseEvent
	{
	private:
		float xPosition = 0.0f;
		float yPosition = 0.0f;

	public:
		constexpr MouseMoveEvent(float xPosition, float yPosition)
			: xPosition(xPosition),
			yPosition(yPosition)
		{
		}

		constexpr float GetXPosition() const
		{
			return xPosition;
		}

		constexpr float GetYPosition() const
		{
			return yPosition;
		}

		virtual std::string ToString() const override;

	protected:
		virtual void DispatchMouseEvent(EventListener &listener) override;
	};
}