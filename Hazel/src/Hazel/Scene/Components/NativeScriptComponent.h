#pragma once

#include "Hazel/Scene/Scripting/NativeScript.h"

namespace Hazel
{
	struct NativeScriptComponent
	{
		std::shared_ptr<NativeScript> Script;
	};

	template<>
	inline void EntityEvents::OnComponentAdded<NativeScriptComponent>(Entity entity, NativeScriptComponent &component)
	{
		component.Script->Attach(entity);
		component.Script->OnCreate();
	}

	template<>
	inline void EntityEvents::OnComponentRemoved<NativeScriptComponent>(Entity entity)
	{
		auto &component = entity.GetComponent<NativeScriptComponent>();
		component.Script->OnDestroy();
		component.Script->Detach();
	}
}