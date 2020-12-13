#pragma once

#include "imgui.h"

#include "Hazel/Scene/Entity.h"
#include "Hazel/ComponentPanels/TagPanel.h"
#include "Hazel/ComponentPanels/TransformPanel.h"
#include "Hazel/ComponentPanels/CameraPanel.h"
#include "Hazel/ComponentPanels/SpritePanel.h"
#include "Hazel/Components/TagComponent.h"
#include "Hazel/Components/TransformComponent.h"
#include "Hazel/Components/CameraComponent.h"
#include "Hazel/Components/SpriteComponent.h"
#include "Private/ComponentNode.h"

namespace Hazel
{
	class PropertiesPanel
	{
	private:
		ComponentNode<TagComponent, TagPanel> tagNode;
		ComponentNode<TransformComponent, TransformPanel> transformNode;
		ComponentNode<CameraComponent, CameraPanel> cameraNode;
		ComponentNode<SpriteComponent, SpritePanel> spriteNode;

	public:
		void Draw(const char *label, Entity entity)
		{
			ImGui::Begin(label);
			if (!entity.IsNull())
			{
				tagNode.Draw(entity.TryGetComponent<TagComponent>());
				transformNode.Draw("Transform", entity.TryGetComponent<TransformComponent>());
				cameraNode.Draw("Camera", entity.TryGetComponent<CameraComponent>());
				spriteNode.Draw("Sprite", entity.TryGetComponent<SpriteComponent>());
			}
			ImGui::End();
		}
	};
}