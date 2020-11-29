#pragma once

#include "ApplicationEvents.h"
#include "ApplicationSetup.h"
#include "ApplicationUpdater.h"

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
				ApplicationUpdater::Update(context);
			}
		}
	};
}