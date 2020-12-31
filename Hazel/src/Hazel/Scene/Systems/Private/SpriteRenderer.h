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
			DrawData drawData;
			AddMesh(drawData);
			AddSprite(drawData, sprite);
			AddTransform(drawData, entity.TryGetComponent<TransformComponent>());
			renderer.Render(drawData);
		}

	private:
		static void AddMesh(DrawData &drawData)
		{
			drawData.Mesh = &SquareMesh::GetMesh();
		}

		static void AddSprite(DrawData &drawData, const SpriteComponent &sprite)
		{
			drawData.Color = &sprite.Color;
			drawData.Texture = &sprite.Texture;
		}

		static void AddTransform(DrawData &drawData, const TransformComponent *transform)
		{
			drawData.Transform = transform ? &transform->Transform : nullptr;
		}
	};
}