#include "SpriteRenderer.h"

namespace Hazel
{
	void SpriteRenderer::RenderSprite(SceneContext &context, entt::entity entity, const SpriteComponent &sprite)
	{
		DrawData drawData;
		AddMesh(drawData);
		AddTransform(drawData, context.Registry.try_get<TransformComponent>(entity));
		AddTexture(drawData, context.Registry.try_get<TextureComponent>(entity));
		AddColor(drawData, sprite);
		context.Renderer->Render(drawData);
	}

	void SpriteRenderer::AddMesh(DrawData &drawData)
	{
		drawData.Mesh = squareMesh.get();
	}

	void SpriteRenderer::AddTransform(DrawData &drawData, const TransformComponent *transform)
	{
		drawData.Transform = transform ? &transform->Transform : nullptr;
	}

	void SpriteRenderer::AddTexture(DrawData &drawData, const TextureComponent *texture)
	{
		drawData.Texture = texture ? &texture->Texture : nullptr;
	}

	void SpriteRenderer::AddColor(DrawData &drawData, const SpriteComponent &sprite)
	{
		drawData.Color = &sprite.Color;
	}
}