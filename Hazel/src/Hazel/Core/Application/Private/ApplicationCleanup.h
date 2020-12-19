#pragma once

#include "ApplicationContext.h"
#include "Hazel/Core/Logging/Log.h"

namespace Hazel
{
	class ApplicationCleanup
	{
	public:
		static void Cleanup(ApplicationContext &context)
		{
			Log::Info("Application cleanup.");
		}
	};
}