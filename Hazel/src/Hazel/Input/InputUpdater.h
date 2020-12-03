#pragma once

#include "Input.h"
#include "Hazel/Events/Event.h"

namespace Hazel
{
	class InputUpdater
	{
	public:
		static void UpdateInput(Input &input, Event &e);
	};
}