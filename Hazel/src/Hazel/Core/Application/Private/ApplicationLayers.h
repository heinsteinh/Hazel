#pragma once

#include <memory>

#include "LayerStack.h"

namespace Hazel
{
	class GuiLayer;

	struct ApplicationLayers
	{
		LayerStack Stack;
		std::shared_ptr<GuiLayer> GuiLayer;
	};
}