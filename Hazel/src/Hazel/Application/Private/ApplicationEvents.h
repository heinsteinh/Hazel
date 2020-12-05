#pragma once

#include "ApplicationContext.h"
#include "Hazel/Events/Event.h"

namespace Hazel
{
	class ApplicationEvents
	{
	public:
		static void ProcessEvent(ApplicationContext &context, Event &e);
	};
}