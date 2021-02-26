#pragma once

#include "imgui.h"

#include "Hazel/Scene/Entity/Entity.h"
#include "Hazel/Editor/ComponentNodes/TagNode.h"
#include "Hazel/Editor/ComponentNodes/TransformNode.h"
#include "Hazel/Editor/ComponentNodes/CameraNode.h"
#include "Hazel/Editor/ComponentNodes/SpriteNode.h"
#include "Hazel/Editor/ComponentNodes/ParticleNode.h"
#include "Hazel/Editor/ComponentNodes/NativeScriptNode.h"
#include "Hazel/Editor/Widgets/Panel.h"
#include "Hazel/Editor/Widgets/Button.h"
#include "Private/ComponentNode.h"
#include "Private/AddComponentPopup.h"

namespace Hazel
{
	class PropertiesPanel
	{
	public:
		static void Draw(const char *label, Entity entity)
		{
			Panel::Begin(label);
			if (entity.IsValid())
			{
				DrawComponents(entity);
			}
			Panel::End();
		}

	private:
		static void DrawComponents(Entity entity)
		{
			ComponentNode<TagComponent, TagNode>::Draw(entity);
			ComponentNode<TransformComponent, TransformNode>::Draw("Transform", entity);
			ComponentNode<CameraComponent, CameraNode>::Draw("Camera", entity);
			ComponentNode<SpriteComponent, SpriteNode>::Draw("Sprite", entity);
			ComponentNode<ParticleComponent, ParticleNode>::Draw("Particle", entity);
			ComponentNode<NativeScriptComponent, NativeScriptNode>::Draw("Native Script", entity);
			DrawAddComponentPopup(entity);
		}

		static void DrawAddComponentPopup(Entity entity)
		{
			if (Button::Draw("AddComponent"))
			{
				AddComponentPopup::Open();
			}
			AddComponentPopup::Draw(entity);
		}
	};
}