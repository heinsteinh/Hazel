#include "ScriptManager.h"

#include "Hazel/Components/ScriptComponent.h"

namespace Hazel
{
	void ScriptManager::OnUpdate(SceneContext &context)
	{
		context.Registry.view<ScriptComponent>().each([](auto entity, auto &component)
		{
			component.Script->OnUpdate();
		});
	}

	void ScriptManager::OnEvent(SceneContext &context, Event &e)
	{
		context.Registry.view<ScriptComponent>().each([&](auto entity, auto &component)
		{
			component.Script->OnEvent(e);
		});
	}
}