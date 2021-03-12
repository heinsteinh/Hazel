#pragma once

#include "Hazel/Scene/Scene/Scene.h"
#include "Hazel/Scene/SceneManager/SceneManager.h"
#include "EntityListPanel.h"
#include "PropertiesPanel.h"

namespace Hazel
{
	class SceneHierarchyPanel
	{
	private:
		SceneManager *manager;

	public:
		SceneHierarchyPanel(SceneManager &manager)
			: manager(&manager)
		{
		}

		void Draw(const char *label, Scene &scene, Entity &selectedEntity)
		{
			EntityListPanel::Draw(label, scene, selectedEntity);
			PropertiesPanel properties(*manager);
			properties.Draw("Properties", selectedEntity);
		}
	};
}