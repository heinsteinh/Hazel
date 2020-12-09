#include "ApplicationMainLoop.h"

#include "ApplicationSetup.h"
#include "ApplicationUpdate.h"
#include "ApplicationEvents.h"

namespace Hazel
{
	void ApplicationMainLoop::Run(ApplicationContext &context)
	{
		ApplicationSetup::Setup(context);
		auto &settings = context.GetSettings();
		settings.Running = true;
		while (settings.Running)
		{
			ApplicationUpdate::MainLoopUpdate(context);
		}
	}
}