#pragma once

#include "Hazel/Scene/SceneContext.h"
#include "Hazel/Components/NativeScriptComponent.h"
#include "Hazel/Events/Event.h"

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

		static void OnImGuiRender(SceneContext &context)
		{
			context.GetRegistry().view<NativeScriptComponent>().each([](auto entity, auto &component)
			{
				component.Script->OnImGuiRender();
			});
		}
	};
}