#pragma once

#include "../SceneContext.h"
#include "Hazel/Events/Event.h"

namespace Hazel
{
	class ScriptManager
	{
	public:
		static void OnUpdate(SceneContext &context);
		static void OnEvent(SceneContext &context, Event &e);
	};
}