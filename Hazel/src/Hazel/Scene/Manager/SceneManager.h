#pragma once

#include "Hazel/Scene/Scene/Scene.h"
#include "Hazel/Scene/Systems/CameraSystem.h"
#include "Hazel/Scene/Systems/NativeScriptSystem.h"
#include "Hazel/Scene/Systems/SpriteRenderingSystem.h"
#include "Hazel/Scene/Systems/ParticleSystem.h"

namespace Hazel
{
	class SceneManager
	{
	private:
		Renderer2D *renderer = nullptr;

	public:
		void SetRenderer(Renderer2D &renderer)
		{
			this->renderer = &renderer;
		}

		void OnUpdate(Scene &scene)
		{
			CameraSystem::OnUpdate(scene);
			NativeScriptSystem::OnUpdate(scene);
			ParticleSystem::OnUpdate(scene);
		}

		void OnRender(Scene &scene)
		{
			if (scene.GetPrimaryCamera().IsValid())
			{
				renderer->BeginScene(scene.GetCamera().ViewProjection);
				SpriteRenderingSystem::OnRender(scene, *renderer);
				ParticleSystem::OnRender(scene, *renderer);
				renderer->EndScene();
			}
		}

		void OnViewportResize(Scene &scene, const Rectangle &viewport)
		{
			CameraSystem::OnViewportResize(scene, viewport);
		}

		void OnEvent(Scene &scene, Event &e)
		{
			NativeScriptSystem::OnEvent(scene, e);
		}
	};
}