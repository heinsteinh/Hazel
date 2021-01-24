#pragma once

#include "Hazel/Scene/Entity/Entity.h"
#include "Hazel/Rendering/Renderer2D/Renderer2D.h"
#include "Hazel/Rendering/Renderer2D/SquareMesh.h"
#include "Hazel/Scene/Components/SpriteComponent.h"
#include "Hazel/Scene/Components/TransformComponent.h"

namespace Hazel
{
	class SpriteRenderer
	{
	public:
		static void RenderSprite(Entity entity, const SpriteComponent &sprite)
		{
			auto &renderer = entity.GetRenderer();
			RenderCommand command;
			command.Mesh = &renderer.GetSquareMesh();
			auto transform = entity.TryGetComponent<TransformComponent>();
			command.Transform = transform ? &transform->Transform : nullptr;
			command.Color = &sprite.Material.Color;
			command.Texture = &sprite.Material.Texture;
			command.Shader = &sprite.Material.Shader;
			renderer.Submit(command);
		}
	};
}