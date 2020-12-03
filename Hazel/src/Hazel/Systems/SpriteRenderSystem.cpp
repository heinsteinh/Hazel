#include "SpriteRenderSystem.h"

#include "Hazel/Systems/SceneCameraSystem.h"
#include "Hazel/Components/CameraComponent.h"
#include "Hazel/Components/SpriteComponent.h"
#include "Hazel/Components/TransformComponent.h"
#include "Hazel/Components/TextureComponent.h"

namespace Hazel
{
	void SpriteRenderSystem::RenderSprites(Scene &scene)
	{
		auto entities = scene.GetAllEntitiesWith<SpriteComponent>();
		for (auto entity : entities)
		{
			RenderSprite(entity, scene.GetRenderer());
		}
	}

	void SpriteRenderSystem::RenderSprite(Entity sprite, Renderer2D &renderer)
	{
		DrawData drawData;
		AddMesh(drawData, sprite);
		AddTransform(drawData, sprite);
		AddTexture(drawData, sprite);
		renderer.Render(drawData);
	}

	void SpriteRenderSystem::AddMesh(DrawData &drawData, Entity sprite)
	{
		drawData.Mesh = squareMesh.get();
		auto &spriteComponent = sprite.GetComponent<SpriteComponent>();
		squareMesh->SetColor(spriteComponent.Color);
	}

	void SpriteRenderSystem::AddTransform(DrawData &drawData, Entity sprite)
	{
		auto transformComponent = sprite.TryGetComponent<TransformComponent>();
		if (transformComponent)
		{
			transform = transformComponent->GetModel();
			drawData.Transform = &transform;
		}
	}

	void SpriteRenderSystem::AddTexture(DrawData &drawData, Entity sprite)
	{
		auto texture = sprite.TryGetComponent<TextureComponent>();
		drawData.Texture = texture ? &texture->Texture : nullptr;
	}
}