#include "SpriteRenderer.h"

#include "Scene.h"
#include "SceneCamera.h"
#include "Hazel/Components/SpriteComponent.h"
#include "Hazel/Components/TransformComponent.h"
#include "Hazel/Components/TextureComponent.h"

namespace Hazel
{
	void SpriteRenderer::RenderSprites(Scene &scene)
	{
		auto entities = scene.GetAllEntitiesWith<SpriteComponent>();
		for (auto entity : entities)
		{
			RenderSprite(entity, scene.GetRenderer());
		}
	}

	void SpriteRenderer::RenderSprite(Entity sprite, Renderer2D &renderer)
	{
		DrawData drawData;
		AddMesh(drawData, sprite);
		AddTransform(drawData, sprite);
		AddTexture(drawData, sprite);
		renderer.Render(drawData);
	}

	void SpriteRenderer::AddMesh(DrawData &drawData, Entity sprite)
	{
		drawData.Mesh = squareMesh.get();
		auto &spriteComponent = sprite.GetComponent<SpriteComponent>();
		squareMesh->SetColor(spriteComponent.Color);
	}

	void SpriteRenderer::AddTransform(DrawData &drawData, Entity sprite)
	{
		auto transform = sprite.TryGetComponent<TransformComponent>();
		drawData.Transform = transform ? &transform->Transform : nullptr;
	}

	void SpriteRenderer::AddTexture(DrawData &drawData, Entity sprite)
	{
		auto texture = sprite.TryGetComponent<TextureComponent>();
		drawData.Texture = texture ? &texture->Texture : nullptr;
	}
}