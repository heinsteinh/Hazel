#pragma once

#include <vector>
#include <memory>

#include "Hazel/Core/Exceptions/AssertionException.h"
#include "Hazel/Scene/SceneManager/SceneManagerView.h"
#include "ComponentSystem.h"

namespace Hazel
{
	class ComponentSystems
	{
	private:
		SceneManagerView manager;
		std::vector<std::unique_ptr<ComponentSystem>> componentSystems;

	public:
		ComponentSystems(SceneManagerView manager)
			: manager(manager)
		{
		}

		void AddComponentSystem(std::unique_ptr<ComponentSystem> componentSystem)
		{
			HZ_ASSERT(componentSystem, "System cannot be null");
			componentSystem->Attach(manager);
			componentSystems.push_back(std::move(componentSystem));
		}

		void OnPlay(Scene &scene) const
		{
			for (const auto &componentSystem : componentSystems)
			{
				componentSystem->OnPlay(scene);
			}
		}

		void OnUpdate(Scene &scene) const
		{
			for (const auto &componentSystem : componentSystems)
			{
				componentSystem->OnUpdate(scene);
			}
		}

		void OnRender(Scene &scene) const
		{
			for (const auto &componentSystem : componentSystems)
			{
				componentSystem->OnRender(scene);
			}
		}

		void OnViewportResize(Scene &scene, const Box2D &viewport) const
		{
			for (const auto &componentSystem : componentSystems)
			{
				componentSystem->OnViewportResize(scene, viewport);
			}
		}

		void OnEvent(Scene &scene, Event &e) const
		{
			for (const auto &componentSystem : componentSystems)
			{
				componentSystem->OnEvent(scene, e);
			}
		}
	};
}