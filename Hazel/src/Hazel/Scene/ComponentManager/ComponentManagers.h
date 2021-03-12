#pragma once

#include <vector>
#include <memory>

#include "Hazel/Core/Exceptions/AssertionException.h"
#include "Hazel/Scene/SceneManager/SceneManagerView.h"
#include "ComponentManager.h"

namespace Hazel
{
	class ComponentManagers
	{
	private:
		SceneManagerView manager;
		std::vector<std::unique_ptr<ComponentManager>> componentManagers;

	public:
		ComponentManagers(SceneManagerView manager)
			: manager(manager)
		{
		}

		void AddComponentManager(std::unique_ptr<ComponentManager> componentManager)
		{
			HZ_ASSERT(componentManager, "Component manager cannot be null");
			componentManager->Attach(manager);
			componentManagers.push_back(std::move(componentManager));
		}

		template<typename FunctorType>
		void ForEach(FunctorType functor) const
		{
			for (const auto &componentManager : componentManagers)
			{
				functor(*componentManager);
			}
		}
	};
}