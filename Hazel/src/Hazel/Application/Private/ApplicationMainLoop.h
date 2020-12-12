#pragma once

#include "ApplicationSetup.h"
#include "ApplicationUpdate.h"

namespace Hazel
{
	class ApplicationMainLoop
	{
	public:
		static void Run(ApplicationContext &context)
		{
			ApplicationSetup::Setup(context);
			auto &settings = context.GetSettings();
			settings.Running = true;
			while (settings.Running)
			{
				ApplicationUpdate::MainLoopUpdate(context);
			}
		}
	};
}