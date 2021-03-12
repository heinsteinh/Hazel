#pragma once

#include "Hazel/Scene/ComponentSystem/ComponentSystem.h"
#include "ScriptComponent.h"

namespace Hazel
{
	class ScriptSystem : public ComponentSystem
	{
	public:
		virtual void OnPlay(Scene &scene) override
		{
			scene.ForEach<ScriptComponent>([&](auto entity, auto &component)
			{
				CreateScript(scene, entity, component);
			});
		}

		virtual void OnUpdate(Scene &scene) override
		{
			scene.ForEach<ScriptComponent>([&](auto entity, auto &component)
			{
				UpdateScript(component);
			});
		}

		virtual void OnEvent(Scene &scene, Event &e) override
		{
			scene.ForEach<ScriptComponent>([&](auto entity, auto &component)
			{
				SendEventToScript(component, e);
			});
		}

	private:
		void CreateScript(Scene &scene, Entity entity, ScriptComponent &component)
		{
			if (!component.Script)
			{
				component.Script = std::make_unique<Script>();
				component.Script->SetName("EmptyScript");
			}
			auto manager = GetSceneManager();
			component.Script->Create(manager, scene, entity);
		}

		void UpdateScript(ScriptComponent &component)
		{
			component.Script->OnUpdate();
		}

		void SendEventToScript(ScriptComponent &component, Event &e)
		{
			component.Script->OnEvent(e);
		}
	};
}