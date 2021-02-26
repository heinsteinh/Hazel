#pragma once

#include "Hazel/Scene/Scene/Scene.h"
#include "EntityPanel.h"
#include "PropertiesPanel.h"

namespace Hazel
{
	class SceneHierarchyPanel
	{
	public:
		static void Draw(const char *label, Scene &scene, Entity &selectedEntity)
		{
			EntityPanel::Draw(label, scene, selectedEntity);
			PropertiesPanel::Draw("Properties", selectedEntity);
		}
	};
}