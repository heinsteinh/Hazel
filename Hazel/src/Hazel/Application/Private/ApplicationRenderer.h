#pragma once

#include "ApplicationContext.h"

namespace Hazel
{
	class ApplicationRenderer
	{
	public:
		static void RenderNewFrame(ApplicationContext &context);
		static void Clear(ApplicationContext &context);
		static void UpdateLayers(ApplicationContext &context);
		static void SwapBuffers(ApplicationContext &context);
	};
}