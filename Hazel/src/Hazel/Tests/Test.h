#pragma once

#include "Hazel/Events/Event.h"

namespace Hazel
{
	class Test
	{
	public:
		virtual ~Test() = default;

		virtual void OnUpdate(float deltaTime)
		{
		}

		virtual void OnImGuiRender()
		{
		}

		virtual void OnEvent(Event &e)
		{
		}
	};
}