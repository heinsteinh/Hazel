#pragma once

#include "Hazel/Events/Event.h"

namespace Hazel
{
	class ApplicationEvent : public Event
	{
	protected:
		virtual void DispatchEvent(EventListener &listener) override;

		virtual void DispatchApplicationEvent(EventListener &listener) = 0;
	};
}