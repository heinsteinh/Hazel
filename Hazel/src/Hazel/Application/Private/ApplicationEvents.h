#pragma once

#include "ApplicationContext.h"
#include "Hazel/Events/Event.h"

namespace Hazel
{
	class ApplicationEvents
	{
	public:
		static void PollEvents(ApplicationContext &context);
		static void ProcessEvent(ApplicationContext &context, Event &e);
	};
}