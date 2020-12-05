#pragma once

#include "Hazel/Scripting/Script.h"

namespace Hazel
{
	struct ScriptComponent
	{
		std::shared_ptr<Script> Script;
	};

	template<>
	inline void EntityEvents::OnAddComponent<ScriptComponent>(Entity entity, ScriptComponent &component)
	{
		component.Script->Attach(entity);
		component.Script->OnCreate();
	}

	template<>
	inline void EntityEvents::OnRemoveComponent<ScriptComponent>(Entity entity)
	{
		auto &component = entity.GetComponent<ScriptComponent>();
		component.Script->OnDestroy();
		component.Script->Detach();
	}
}