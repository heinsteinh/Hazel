#pragma once

#include "imgui.h"

#include "Hazel/Scene/Scene/Scene.h"
#include "Hazel/Editor/Widgets/Panel.h"
#include "Private/CreateEntityPopup.h"
#include "Private/EntityNode.h"

namespace Hazel
{
	class EntityPanel
	{
	public:
		static void Draw(const char *label, Scene &scene, Entity &selectedEntity)
		{
			Panel::Begin(label);
			scene.ForEach([&](auto entity)
			{
				DrawEntity(scene, entity, selectedEntity);
			});
			if (Panel::IsClicked())
			{
				selectedEntity = {};
			}
			CreateEntityPopup::Draw(scene);
			Panel::End();
		}

	private:
		static void DrawEntity(Scene &scene, Entity entity, Entity &selectedEntity)
		{
			auto status = EntityNode::Draw(entity, selectedEntity);
			if (status.EntityDestroyed)
			{
				if (entity == selectedEntity)
				{
					selectedEntity = {};
				}
				scene.DestroyEntity(entity);
			}
		}
	};
}