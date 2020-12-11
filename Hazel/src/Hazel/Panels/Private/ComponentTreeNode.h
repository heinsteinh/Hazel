#pragma once

#include "imgui.h"

#include "Hazel/Scene/Entity.h"
#include "ComponentPanelHelper.h"

namespace Hazel
{
	template<typename ComponentType, typename PanelType>
	class ComponentTreeNode
	{
	private:
		PanelType panel;

	public:
		bool Begin(const char *label)
		{
			return ImGui::TreeNodeEx(
				ComponentPanelHelper::GetComponentId<ComponentType>(),
				ImGuiTreeNodeFlags_DefaultOpen,
				label);
		}

		void Draw(const char *label, Entity entity)
		{
			Draw(label, entity.TryGetComponent<ComponentType>());
		}

		void Draw(Entity entity)
		{
			Draw(entity.TryGetComponent<ComponentType>());
		}

		void Draw(const char *label, ComponentType *component)
		{
			if (component && Begin(label))
			{
				panel.Draw(*component);
				End();
			}
		}

		void Draw(ComponentType *component)
		{
			if (component)
			{
				panel.Draw(*component);
			}
		}

		void End()
		{
			ImGui::TreePop();
		}
	};
}