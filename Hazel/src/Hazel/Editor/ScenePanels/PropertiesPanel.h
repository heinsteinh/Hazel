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
				DrawAddComponent(entity);
			}
			Panel::End();
		}

	private:
		static void DrawComponents(Entity entity)
		{
			DrawTag(entity);
			DrawTransform("Transform", entity);
			DrawComponent<CameraComponent, CameraNode>("Camera", entity);
			DrawComponent<SpriteComponent, SpriteNode>("Sprite", entity);
			DrawComponent<ParticleComponent, ParticleNode>("Particle", entity);
			DrawComponent<NativeScriptComponent, NativeScriptNode>("Native Script", entity);
		}

		static void DrawTag(Entity entity)
		{
			TagNode::Draw(entity.GetTag());
		}

		static void DrawTransform(const char *label, Entity entity)
		{
			if (ComponentNode<TransformComponent>::Begin(label))
			{
				TransformNode::Draw(entity.GetTransform());
				ComponentNode<TransformComponent>::End();
			}
		}

		static void DrawAddComponent(Entity entity)
		{
			if (Button::Draw("AddComponent"))
			{
				AddComponentPopup::Open();
			}
			AddComponentPopup::Draw(entity);
		}

		template<typename ComponentType, typename NodeType>
		static void DrawComponent(const char *label, Entity entity)
		{
			auto component = entity.TryGetComponent<ComponentType>();
			if (component && ComponentNode<ComponentType>::Begin(label))
			{
				NodeType::Draw(entity, *component);
				ComponentNode<ComponentType>::DrawRemoveComponent(entity);
				ComponentNode<ComponentType>::End();
			}
		}
	};
}