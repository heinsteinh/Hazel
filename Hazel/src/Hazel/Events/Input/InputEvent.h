#pragma once

#include "Hazel/Events/Event.h"

namespace Hazel
{
	class InputEvent : public Event
	{
	public:
		virtual void DispatchEvent(EventListener &listener) override;

		virtual void DispatchInputEvent(EventListener &listener) = 0;
	};
}