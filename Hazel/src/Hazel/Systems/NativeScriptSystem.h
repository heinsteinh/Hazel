#pragma once

#include "Hazel/Scene/SceneContext.h"
#include "Hazel/Events/Event.h"

namespace Hazel
{
	class NativeScriptSystem
	{
	public:
		static void OnUpdate(SceneContext &context);
		static void OnEvent(SceneContext &context, Event &e);
		static void OnImGuiRender(SceneContext &context);
	};
}