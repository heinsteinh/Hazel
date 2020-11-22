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
			ApplicationUpdater::Init(context);
			context.SetRunning(true);
			while (context.IsRunning())
			{
				ApplicationUpdater::Update(context);
			}
		}
	};
}