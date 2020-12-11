#pragma once

#include "EntityPanel.h"
#include "PropertiesPanel.h"

namespace Hazel
{
	class SceneHierarchyPanel
	{
	private:
		Entity selectedEntity;
		EntityPanel entityPanel;
		PropertiesPanel propertiesPanel;

	public:
		void Draw(const char *label, Scene &scene)
		{
			DrawEntities(label, scene);
			propertiesPanel.Draw("Properties", selectedEntity);
		}

	private:
		void DrawEntities(const char *label, Scene &scene)
		{
			ImGui::Begin(label);
			scene.ForEach([this](auto entity)
			{
				entityPanel.Draw(entity, selectedEntity);
			});
			if (WantDeselectEntity())
			{
				selectedEntity = {};
			}
			ImGui::End();
		}

		bool WantDeselectEntity() const
		{
			return ImGui::IsMouseDown(ImGuiMouseButton_Left) && ImGui::IsWindowHovered();
		}
	};
}