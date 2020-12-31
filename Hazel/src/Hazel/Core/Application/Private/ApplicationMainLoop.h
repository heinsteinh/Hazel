#pragma once

#include "ApplicationSetup.h"
#include "ApplicationUpdate.h"
#include "ApplicationLayers.h"

namespace Hazel
{
	class ApplicationMainLoop
	{
	public:
		static void Run(ApplicationInfo &info, ApplicationContext &context, ApplicationLayers &layers)
		{
			ApplicationSetup::Setup(info, context, layers);
			context.Settings.Running = true;
			while (context.Settings.Running)
			{
				ApplicationUpdate::MainLoopUpdate(context, layers);
			}
		}
	};
}