#include "SpriteRenderer.h"

#include "Hazel/Rendering/SquareMesh.h"

namespace Hazel
{
	void SpriteRenderer::RenderSprite(SceneContext &context, entt::entity entity, const SpriteComponent &sprite)
	{
		auto &registry = context.GetRegistry();
		DrawData drawData;
		AddMesh(drawData);
		AddSprite(drawData, sprite);
		AddTransform(drawData, registry.try_get<TransformComponent>(entity));
		context.GetRenderer().Render(drawData);
	}

	void SpriteRenderer::AddMesh(DrawData &drawData)
	{
		drawData.Mesh = &SquareMesh::GetMesh();
	}

	void SpriteRenderer::AddSprite(DrawData &drawData, const SpriteComponent &sprite)
	{
		drawData.Color = &sprite.Color;
		drawData.Texture = &sprite.Texture;
	}

	void SpriteRenderer::AddTransform(DrawData &drawData, const TransformComponent *transform)
	{
		drawData.Transform = transform ? &transform->Transform : nullptr;
	}
}