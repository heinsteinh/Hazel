#pragma once

#include "imgui.h"

#include "Hazel/Scene/Entity.h"
#include "TagPanel.h"
#include "TransformPanel.h"
#include "CameraPanel.h"
#include "SpritePanel.h"
#include "Hazel/Components/TagComponent.h"
#include "Hazel/Components/TransformComponent.h"
#include "Hazel/Components/CameraComponent.h"
#include "Hazel/Components/SpriteComponent.h"
#include "Private/ComponentTreeNode.h"

namespace Hazel
{
	class PropertiesPanel
	{
	private:
		ComponentTreeNode<TagComponent, TagPanel> tagNode;
		ComponentTreeNode<TransformComponent, TransformPanel> transformNode;
		ComponentTreeNode<CameraComponent, CameraPanel> cameraNode;
		ComponentTreeNode<SpriteComponent, SpritePanel> spriteNode;

	public:
		void Draw(const char *label, Entity entity)
		{
			ImGui::Begin(label);
			if (entity.IsValid())
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