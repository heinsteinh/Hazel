#include "NativeScriptManager.h"

#include "Hazel/Components/NativeScriptComponent.h"

namespace Hazel
{
	void NativeScriptManager::OnUpdate(SceneContext &context)
	{
		context.Registry.view<NativeScriptComponent>().each([](auto entity, auto &component)
		{
			component.Script->OnUpdate();
		});
	}

	void NativeScriptManager::OnEvent(SceneContext &context, Event &e)
	{
		context.Registry.view<NativeScriptComponent>().each([&](auto entity, auto &component)
		{
			component.Script->OnEvent(e);
		});
	}

	void NativeScriptManager::OnImGuiRender(SceneContext &context)
	{
		context.Registry.view<NativeScriptComponent>().each([&](auto entity, auto &component)
		{
			component.Script->OnImGuiRender();
		});
	}
}