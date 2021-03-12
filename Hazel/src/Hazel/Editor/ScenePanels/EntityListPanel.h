#pragma once

#include "imgui.h"

#include "Hazel/Scene/Scene/Scene.h"
#include "Hazel/Editor/Widgets/Panel.h"
#include "Private/CreateEntityPopup.h"
#include "Private/EntityNode.h"

namespace Hazel
{
	class EntityListPanel
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
			if (CreateEntityPopup::Draw().EntityCreated)
			{
				scene.CreateEntity("New Entity");
			}
			Panel::End();
		}

	private:
		static void DrawEntity(Scene &scene, Entity entity, Entity &selectedEntity)
		{
			if (EntityNode::Draw(entity, selectedEntity).EntityDestroyed)
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