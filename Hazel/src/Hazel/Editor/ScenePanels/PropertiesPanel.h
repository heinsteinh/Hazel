#pragma once

#include "imgui.h"

#include "Hazel/Scene/Scene/Entity.h"
#include "Hazel/Scene/Components/TagComponent.h"
#include "Hazel/Scene/Components/TransformComponent.h"
#include "Hazel/Scene/Components/CameraComponent.h"
#include "Hazel/Scene/Components/SpriteComponent.h"

#include "Hazel/Editor/ComponentPanels/TagPanel.h"
#include "Hazel/Editor/ComponentPanels/TransformPanel.h"
#include "Hazel/Editor/ComponentPanels/CameraPanel.h"
#include "Hazel/Editor/ComponentPanels/SpritePanel.h"
#include "Private/ComponentNode.h"
#include "Private/AddComponentMenu.h"

namespace Hazel
{
	class PropertiesPanel
	{
	private:
		ComponentNode<TagComponent, TagPanel> tagNode;
		ComponentNode<TransformComponent, TransformPanel> transformNode;
		ComponentNode<CameraComponent, CameraPanel> cameraNode;
		ComponentNode<SpriteComponent, SpritePanel> spriteNode;
		AddComponentMenu addComponentMenu;

	public:
		void Draw(const char *label, Entity entity)
		{
			ImGui::Begin(label);
			if (!entity.IsNull())
			{
				DrawComponents(entity);
				addComponentMenu.Draw("Add Component", entity);
			}
			ImGui::End();
		}

	private:
		void DrawComponents(Entity entity)
		{
			tagNode.Draw(entity);
			transformNode.Draw("Transform", entity);
			cameraNode.Draw("Camera", entity);
			spriteNode.Draw("Sprite", entity);
		}
	};
}