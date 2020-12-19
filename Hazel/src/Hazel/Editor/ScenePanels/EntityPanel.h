#pragma once

#include "imgui.h"

#include "Hazel/Scene/Scene/Scene.h"
#include "Private/EntityPanelPopup.h"
#include "Private/EntityNode.h"

namespace Hazel
{
	class EntityPanel
	{
	private:
		EntityPanelPopup popup;
		EntityNode node;

	public:
		void Draw(const char *label, Scene &scene, Entity &selectedEntity)
		{
			ImGui::Begin(label);
			scene.ForEach([&](auto entity)
			{
				DrawEntity(scene, entity, selectedEntity);
			});
			if (WantDeselectEntity())
			{
				selectedEntity = {};
			}
			popup.Draw(scene);
			ImGui::End();
		}

	private:
		void DrawEntity(Scene &scene, Entity entity, Entity &selectedEntity)
		{
			node.Draw(entity, selectedEntity);
			if (node.WantDestroyEntity())
			{
				if (entity == selectedEntity)
				{
					selectedEntity = {};
				}
				scene.DestroyEntity(entity);
			}
		}

		bool WantDeselectEntity() const
		{
			return ImGui::IsMouseDown(ImGuiMouseButton_Left) && ImGui::IsWindowHovered();
		}
	};
}