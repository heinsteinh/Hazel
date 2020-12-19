#pragma once

#include "Hazel/Scene/Scene/SceneContext.h"
#include "Hazel/Scene/Components/NativeScriptComponent.h"
#include "Hazel/Core/Events/Event.h"

namespace Hazel
{
	class NativeScriptSystem
	{
	public:
		static void OnUpdate(SceneContext &context)
		{
			context.GetRegistry().view<NativeScriptComponent>().each([](auto entity, auto &component)
			{
				component.Script->OnUpdate();
			});
		}

		static void OnEvent(SceneContext &context, Event &e)
		{
			context.GetRegistry().view<NativeScriptComponent>().each([&](auto entity, auto &component)
			{
				component.Script->OnEvent(e);
			});
		}

		static void OnGui(SceneContext &context)
		{
			context.GetRegistry().view<NativeScriptComponent>().each([](auto entity, auto &component)
			{
				component.Script->OnGui();
			});
		}
	};
}