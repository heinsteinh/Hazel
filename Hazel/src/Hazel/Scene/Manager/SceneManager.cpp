#include "SceneManager.h"

#include "Hazel/Scene/Systems/CameraSystem.h"
#include "Hazel/Scene/Systems/NativeScriptSystem.h"
#include "Hazel/Scene/Systems/SpriteRenderingSystem.h"
#include "Hazel/Scene/Systems/ParticleSystem.h"

namespace Hazel
{
	std::shared_ptr<Scene> SceneManager::CreateScene(const std::string &name)
	{
		return std::make_shared<Scene>(name, context);
	}

	void SceneManager::ResetRenderer(const RendererInfo &rendererInfo)
	{
		context.Renderer = std::make_unique<Renderer2D>(context.Layer->GetGraphicsContext(), rendererInfo);
	}

	void SceneManager::OnAttach(Layer &layer, const RendererInfo &rendererInfo)
	{
		context.Layer = &layer;
		auto &graphicsContext = layer.GetGraphicsContext();
		context.Renderer = std::make_unique<Renderer2D>(graphicsContext, rendererInfo);
		context.TextureManager = std::make_unique<TextureManager>(graphicsContext);
	}

	void SceneManager::OnUpdate(Scene &scene)
	{
		CameraSystem::OnUpdate(scene);
		NativeScriptSystem::OnUpdate(scene);
		ParticleSystem::OnUpdate(scene);
	}

	void SceneManager::OnRender(Scene &scene)
	{
		if (scene.GetPrimaryCamera().IsValid())
		{
			context.Renderer->BeginScene(scene.GetCamera().ViewProjection);
			SpriteRenderingSystem::OnRender(scene);
			ParticleSystem::OnRender(scene);
			context.Renderer->EndScene();
		}
	}

	void SceneManager::OnViewportResize(Scene &scene, const Rectangle &viewport)
	{
		CameraSystem::OnViewportResize(scene, viewport);
	}

	void SceneManager::OnEvent(Scene &scene, Event &e)
	{
		NativeScriptSystem::OnEvent(scene, e);
	}
}