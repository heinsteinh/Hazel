#pragma once

#include "Hazel/Scene/Scene/Entity.h"
#include "Hazel/Scene/ComponentManager/ComponentManagers.h"
#include "Hazel/Editor/Widgets/Button.h"
#include "Hazel/Editor/Widgets/Popup.h"

namespace Hazel
{
	class AddComponentPopup
	{
	private:
		static constexpr const char *id = "AddComponent";

	public:
		static void Open()
		{
			Popup::Open(id);
		}

		static bool Draw(Entity entity, const ComponentManagers &componentManagers)
		{
			bool changed = false;
			if (Popup::Begin(id))
			{
				componentManagers.ForEach([&](auto &componentManager)
				{
					changed |= DrawItem(entity, componentManager);
				});
				Popup::End();
			}
			return changed;
		}

	private:
		static bool DrawItem(Entity entity, ComponentManager &componentManager)
		{
			auto label = componentManager.GetComponentName().c_str();
			if (Popup::DrawItem(label) && !componentManager.HasComponent(entity))
			{
				componentManager.AddComponent(entity);
				Popup::Close();
				return true;
			}
			return false;
		}
	};
}