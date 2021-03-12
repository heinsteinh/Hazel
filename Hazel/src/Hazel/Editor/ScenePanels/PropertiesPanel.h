#pragma once

#include "Hazel/Scene/SceneManager/SceneManager.h"
#include "Hazel/Scene/Scene/Entity.h"
#include "Hazel/Scene/Components/Tag/TagWidget.h"
#include "Hazel/Scene/Components/Transform/TransformWidget.h"
#include "Hazel/Editor/Widgets/Panel.h"
#include "Hazel/Editor/Widgets/Button.h"
#include "Private/ComponentNode.h"
#include "Private/AddComponentPopup.h"

namespace Hazel
{
	class PropertiesPanel
	{
	private:
		SceneManager *manager;

	public:
		PropertiesPanel(SceneManager &manager)
			: manager(&manager)
		{
		}

		void Draw(const char *label, Entity entity)
		{
			Panel::Begin(label);
			if (entity.IsValid())
			{
				DrawComponents(entity);
				DrawAddComponent(entity);
			}
			Panel::End();
		}

	private:
		void DrawComponents(Entity entity)
		{
			DrawTag(entity);
			DrawTransform("Transform", entity);
			manager->GetComponentManagers().ForEach([&](auto &componentManager)
			{
				DrawComponent(entity, componentManager);
			});
		}

		void DrawTag(Entity entity)
		{
			TagWidget::Draw(entity.GetTag());
		}

		void DrawTransform(const char *label, Entity entity)
		{
			if (ComponentNode::Begin(label))
			{
				TransformWidget::Draw(entity.GetTransform());
				ComponentNode::End();
			}
		}

		void DrawAddComponent(Entity entity)
		{
			if (Button::Draw("Add Component"))
			{
				AddComponentPopup::Open();
			}
			AddComponentPopup::Draw(entity, manager->GetComponentManagers());
		}

		static void DrawComponent(Entity entity, ComponentManager &componentManager)
		{
			if (!componentManager.HasComponent(entity))
			{
				return;
			}
			auto label = componentManager.GetComponentName().c_str();
			if (ComponentNode::Begin(label))
			{
				componentManager.DrawComponent(entity);
				if (ComponentNode::DrawRemoveComponent())
				{
					componentManager.RemoveComponent(entity);
				}
				ComponentNode::End();
			}
		}
	};
}