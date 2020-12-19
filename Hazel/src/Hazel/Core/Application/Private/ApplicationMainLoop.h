#pragma once

#include "ApplicationSetup.h"
#include "ApplicationUpdate.h"
#include "ApplicationCleanup.h"

namespace Hazel
{
	class ApplicationMainLoop
	{
	public:
		static void Run(ApplicationInfo &info, ApplicationContext &context)
		{
			ApplicationSetup::Setup(info, context);
			context.Settings.Running = true;
			while (context.Settings.Running)
			{
				ApplicationUpdate::MainLoopUpdate(context);
			}
			ApplicationCleanup::Cleanup(context);
		}
	};
}