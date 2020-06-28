#pragma once

#include "ApplicationEvent.h"
#include "Hazel/Utils/Size.h"

namespace Hazel
{
	class WindowResizeEvent : public ApplicationEvent
	{
	private:
		Size size;

	public:
		constexpr WindowResizeEvent(float width, float height)
			: size{width, height}
		{
		}

		constexpr Size GetSize() const
		{
			return size;
		}

		virtual std::string ToString() const override;

	protected:
		virtual void DispatchApplicationEvent(EventListener &listener) override;
	};
}