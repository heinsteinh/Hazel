#pragma once

#include "ApplicationContext.h"

namespace Hazel
{
	class ApplicationRenderer
	{
	public:
		static void BeginFrame(ApplicationContext &context);
		static void RenderFrame(ApplicationContext &context);
		static void RenderImGui(ApplicationContext &context);
		static void EndFrame(ApplicationContext &context);
	};
}