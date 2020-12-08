#include "NativeScriptSystem.h"

#include "Hazel/Components/NativeScriptComponent.h"

namespace Hazel
{
	void NativeScriptSystem::OnUpdate(SceneContext &context)
	{
		context.GetRegistry().view<NativeScriptComponent>().each([](auto entity, auto &component)
		{
			component.Script->OnUpdate();
		});
	}

	void NativeScriptSystem::OnEvent(SceneContext &context, Event &e)
	{
		context.GetRegistry().view<NativeScriptComponent>().each([&](auto entity, auto &component)
		{
			component.Script->OnEvent(e);
		});
	}

	void NativeScriptSystem::OnImGuiRender(SceneContext &context)
	{
		context.GetRegistry().view<NativeScriptComponent>().each([&](auto entity, auto &component)
		{
			component.Script->OnImGuiRender();
		});
	}
}