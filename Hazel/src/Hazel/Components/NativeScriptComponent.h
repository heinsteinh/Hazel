#pragma once

#include "Hazel/Scripting/NativeScript.h"

namespace Hazel
{
	struct NativeScriptComponent
	{
		std::shared_ptr<NativeScript> Script;
	};

	template<>
	inline void EntityEvents::OnAddComponent<NativeScriptComponent>(Entity entity, NativeScriptComponent &component)
	{
		component.Script->Attach(entity);
		component.Script->OnCreate();
	}

	template<>
	inline void EntityEvents::OnRemoveComponent<NativeScriptComponent>(Entity entity)
	{
		auto &component = entity.GetComponent<NativeScriptComponent>();
		component.Script->OnDestroy();
		component.Script->Detach();
	}
}