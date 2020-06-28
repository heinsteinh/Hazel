#pragma once

#include "MouseEvent.h"

namespace Hazel
{
	class MouseScrollEvent : public MouseEvent
	{
	private:
		float xOffset = 0.0f;
		float yOffset = 0.0f;

	public:
		constexpr MouseScrollEvent(float xOffset, float yOffset)
			: xOffset(xOffset),
			yOffset(yOffset)
		{
		}

		constexpr float GetXOffset() const
		{
			return xOffset;
		}

		constexpr float GetYOffset() const
		{
			return yOffset;
		}

		virtual std::string ToString() const override;

	protected:
		virtual void DispatchMouseEvent(EventListener &listener) override;
	};
}