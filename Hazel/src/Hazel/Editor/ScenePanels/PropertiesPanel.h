#pragma once

#include "imgui.h"

#include "Hazel/Scene/Entity/Entity.h"
#include "Hazel/Editor/ComponentPanels/TagPanel.h"
#include "Hazel/Editor/ComponentPanels/TransformPanel.h"
#include "Hazel/Editor/ComponentPanels/CameraPanel.h"
#include "Hazel/Editor/ComponentPanels/SpritePanel.h"
#include "Hazel/Editor/ComponentPanels/ParticlePanel.h"
#include "Hazel/Editor/ComponentPanels/NativeScriptPanel.h"
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
		ComponentNode<ParticleComponent, ParticlePanel> particleNode;
		ComponentNode<NativeScriptComponent, NativeScriptPanel> nativeScriptNode;
		AddComponentMenu addComponentMenu;

	public:
		void Draw(const char *label, Entity entity)
		{
			ImGui::Begin(label);
			if (entity.IsValid())
			{
				DrawComponents(entity);
			}
			ImGui::End();
		}

	private:
		void DrawComponents(Entity entity)
		{
			tagNode.Draw(entity);
			ImGui::SameLine();
			ImGui::PushItemWidth(-1);
			addComponentMenu.Draw("Add Component", entity);
			ImGui::PopItemWidth();
			transformNode.Draw("Transform", entity);
			cameraNode.Draw("Camera", entity);
			spriteNode.Draw("Sprite", entity);
			particleNode.Draw("Particle", entity);
			nativeScriptNode.Draw("Native Script", entity);
		}
	};
}