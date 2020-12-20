#pragma once

#include "imgui.h"

#include "Hazel/Scene/Entity/Entity.h"
#include "ComponentSettingsMenu.h"
#include "Hazel/Editor/Utils/TreeNodeFlags.h"

namespace Hazel
{
	template<typename ComponentType, typename PanelType>
	class ComponentNode
	{
	private:
		static inline void *hashCode = reinterpret_cast<void *>(typeid(ComponentType).hash_code());

		PanelType panel;
		ComponentSettingsMenu settingsMenu;

	public:
		void Draw(const char *label, Entity entity)
		{
			auto component = entity.TryGetComponent<ComponentType>();
			if (component && Begin(label))
			{
				Draw(entity, *component);
				End();
			}
		}

		void Draw(Entity entity)
		{
			auto component = entity.TryGetComponent<ComponentType>();
			if (component)
			{
				Draw(entity, *component);
			}
		}

	private:
		bool Begin(const char *label)
		{
			bool open = ImGui::TreeNodeEx(hashCode, TreeNodeFlags::GetDefaultFlags(), label);
			ImGui::SameLine(ImGui::GetWindowWidth() - 25.0f);
			settingsMenu.Draw();
			return open;
		}

		void Draw(Entity entity, ComponentType &component)
		{
			panel.Draw(component);
			if (settingsMenu.WantRemoveComponent())
			{
				entity.RemoveComponent<ComponentType>();
			}
		}

		void End()
		{
			ImGui::TreePop();
		}
	};
}