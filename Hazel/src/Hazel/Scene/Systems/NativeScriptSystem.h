#pragma once

#include "Hazel/Scene/Entity/SceneContext.h"
#include "Hazel/Scene/Components/NativeScriptComponent.h"
#include "Hazel/Core/Events/Event.h"

namespace Hazel
{
	class NativeScriptSystem
	{
	public:
		static void OnUpdate(SceneContext &context)
		{
			context.Registry.view<NativeScriptComponent>().each([](auto entity, auto &component)
			{
				component.Script->OnUpdate();
			});
		}

		static void OnEvent(SceneContext &context, Event &e)
		{
			context.Registry.view<NativeScriptComponent>().each([&](auto entity, auto &component)
			{
				component.Script->OnEvent(e);
			});
		}
	};
}