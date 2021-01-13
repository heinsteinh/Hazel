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
		static void RenderSprite(Renderer2D &renderer, Entity entity, const SpriteComponent &sprite)
		{
			RenderCommand command;
			command.Mesh = &entity.GetRenderer().GetSquareMesh();
			command.Material = &sprite.Material;
			auto transform = entity.TryGetComponent<TransformComponent>();
			command.Transform = transform ? &transform->Transform : nullptr;
			renderer.Submit(command);
		}
	};
}