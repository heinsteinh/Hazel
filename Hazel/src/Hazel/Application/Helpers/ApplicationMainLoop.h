#pragma once

#include "ApplicationEvents.h"
#include "ApplicationSetup.h"
#include "ApplicationUpdater.h"

namespace Hazel
{
	class ApplicationMainLoop
	{
	public:
		static inline void Run(ApplicationContext &context)
		{
			ApplicationSetup::Setup(context);
			context.SetRunning(true);
			while (context.IsRunning())
			{
				ApplicationUpdater::Update(context);
			}
		}
	};
}