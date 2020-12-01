#pragma once

#include "Scene.h"
#include "CameraEntity.h"
#include "Hazel/Rendering/SquareMesh.h"
#include "Hazel/Rendering/Renderer2D.h"
#include "Hazel/Geometry/MvpMatrix.h"
#include "Hazel/Components/CameraComponent.h"
#include "Hazel/Components/SpriteComponent.h"
#include "Hazel/Components/TransformComponent.h"
#include "Hazel/Components/TextureComponent.h"

namespace Hazel
{
	class SceneRenderer
	{
	private:
		DrawData drawData = {SquareMesh::CreateMesh()};

	public:
		void Render(Scene &scene, Renderer2D &renderer)
		{
			if (!BeginScene(scene, renderer))
			{
				return;
			}
			RenderSprites(scene, renderer);
			renderer.EndScene();
		}

	private:
		bool BeginScene(Scene &scene, Renderer2D &renderer)
		{
			auto view = scene.GetAllEntitiesWith<CameraComponent>();
			if (view.IsEmpty())
			{
				return false;
			}
			renderer.BeginScene(CameraEntity::GetViewProjection(view.GetFirstEntity()));
			return true;
		}

		void RenderSprites(Scene &scene, Renderer2D &renderer)
		{
			auto view = scene.GetAllEntitiesWith<SpriteComponent>();
			for (auto entity : view)
			{
				auto &sprite = entity.GetComponent<SpriteComponent>();
				auto transform = entity.TryGetComponent<TransformComponent>();
				auto texture = entity.TryGetComponent<TextureComponent>();
				drawData.Mesh->SetColor(sprite.Color);
				drawData.Texture = texture ? *texture : SubTexture();
				drawData.Transform = transform ? *transform : Transform();
				renderer.Render(drawData);
			}
		}
	};
}