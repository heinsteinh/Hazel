#include "SceneRenderer.h"

namespace Hazel
{
	void SceneRenderer::RenderSprites(SceneContext &context)
	{
		auto view = context.Registry.view<SpriteComponent>();
		for (auto entity : view)
		{
			RenderSprite(context, entity, view.get<SpriteComponent>(entity));
		}
	}

	void SceneRenderer::RenderSprite(SceneContext &context, entt::entity entity, const SpriteComponent &sprite)
	{
		DrawData drawData;
		AddMesh(drawData);
		AddTransform(drawData, context.Registry.try_get<TransformComponent>(entity));
		AddTexture(drawData, context.Registry.try_get<TextureComponent>(entity));
		AddColor(drawData, sprite);
		context.Renderer->Render(drawData);
	}

	void SceneRenderer::AddMesh(DrawData &drawData)
	{
		drawData.Mesh = squareMesh.get();
	}

	void SceneRenderer::AddTransform(DrawData &drawData, const TransformComponent *transform)
	{
		drawData.Transform = transform ? &transform->Transform : nullptr;
	}

	void SceneRenderer::AddTexture(DrawData &drawData, const TextureComponent *texture)
	{
		drawData.Texture = texture ? &texture->Texture : nullptr;
	}

	void SceneRenderer::AddColor(DrawData &drawData, const SpriteComponent &sprite)
	{
		drawData.Color = &sprite.Color;
	}
}