#pragma once

#include "ApplicationEvents.h"
#include "ApplicationUpdater.h"

namespace Hazel
{
	class ApplicationMainLoop
	{
	public:
		static inline void Run(ApplicationContext &context)
		{
			context.SetEventCallback([&](Event &e)
			{
				ApplicationEvents::ProcessEvent(context, e);
			});
			context.SetRunning(true);
			while (context.IsRunning())
			{
				ApplicationUpdater::Update(context);
			}
		}
	};
}