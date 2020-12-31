#pragma once

#include "Hazel/Scene/Scene/Scene.h"
#include "Hazel/Scene/Components/NativeScriptComponent.h"
#include "Hazel/Core/Events/Event.h"

namespace Hazel
{
	class NativeScriptSystem
	{
	public:
		static void OnUpdate(Scene &scene)
		{
			scene.ForEach<NativeScriptComponent>([](auto entity, auto &component)
			{
				component.Script->OnUpdate();
			});
		}

		static void OnEvent(Scene &scene, Event &e)
		{
			scene.ForEach<NativeScriptComponent>([&](auto entity, auto &component)
			{
				component.Script->OnEvent(e);
			});
		}
	};
}