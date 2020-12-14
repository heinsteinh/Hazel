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
			entityPanel.Draw(label, scene, selectedEntity);
			propertiesPanel.Draw("Properties", selectedEntity);
		}
	};
}