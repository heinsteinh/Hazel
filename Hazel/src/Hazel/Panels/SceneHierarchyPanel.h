#pragma once

#include "EntityPanel.h"

namespace Hazel
{
	class SceneHierarchyPanel
	{
	private:
		EntityPanel entityPanel;
		Entity selectedEntity;

	public:
		void Draw(const char *label, Scene &scene)
		{
			ImGui::Begin(label);
			scene.ForEach([this](auto entity)
			{
				entityPanel.Draw(entity, selectedEntity);
			});
			ImGui::End();
		}
	};
}