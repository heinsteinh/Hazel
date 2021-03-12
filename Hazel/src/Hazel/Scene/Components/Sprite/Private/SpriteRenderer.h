#pragma once

#include "Hazel/Rendering/Renderer2D/Renderer2D.h"
#include "Hazel/Scene/Scene/Entity.h"
#include "Hazel/Scene/Components/Sprite/SpriteComponent.h"

namespace Hazel
{
	class SpriteRenderer
	{
	private:
		Renderer2D *renderer;

	public:
		SpriteRenderer(Renderer2D &renderer)
			: renderer(&renderer)
		{
		}

		void RenderSprite(Entity entity, const SpriteComponent &sprite)
		{
			auto &command = renderer->AddRenderCommand();
			command.Mesh = renderer->GetSquareMesh();
			command.Transform = entity.GetTransform();
			command.Color = sprite.Material.Color;
			command.Texture = sprite.Material.Texture;
			command.Shader = sprite.Material.Shader ? sprite.Material.Shader : renderer->GetDefaultShader();
			command.Transparency = sprite.Material.Transparency;
		}
	};
}