#pragma once

#include "ApplicationContext.h"

namespace Hazel
{
	class ApplicationUpdate
	{
	public:
		static void MainLoopUpdate(ApplicationContext &context);
		static void WindowResizeUpdate(ApplicationContext &context);
	};
}