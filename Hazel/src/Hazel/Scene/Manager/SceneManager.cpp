#include "SceneManager.h"

#include "Hazel/Scene/Systems/CameraSystem.h"
#include "Hazel/Scene/Systems/NativeScriptSystem.h"
#include "Hazel/Scene/Systems/SpriteRenderingSystem.h"
#include "Hazel/Scene/Systems/ParticleSystem.h"
#include "Hazel/Rendering/Renderer2D/Shader2D.h"

namespace Hazel
{
	std::shared_ptr<Scene> SceneManager::CreateScene(const std::string &name)
	{
		return std::make_shared<Scene>(name, context);
	}

	void SceneManager::ResetRenderer(const RendererInfo &rendererInfo)
	{
		context.Renderer = std::make_unique<Renderer2D>(rendererInfo);
	}

	void SceneManager::OnAttach(Layer &layer, const RendererInfo &rendererInfo)
	{
		context.Layer = &layer;
		context.Renderer = std::make_unique<Renderer2D>(rendererInfo);
	}

	void SceneManager::OnPlay(Scene &scene)
	{
		NativeScriptSystem::OnPlay(scene);
	}

	void SceneManager::OnUpdate(Scene &scene)
	{
		CameraSystem::OnUpdate(scene);
		NativeScriptSystem::OnUpdate(scene);
		ParticleSystem::OnUpdate(scene);
	}

	void SceneManager::OnRender(Scene &scene, const std::shared_ptr<Framebuffer> &framebuffer)
	{
		if (scene.GetPrimaryCamera().IsValid())
		{
			context.Renderer->BeginScene(scene.GetCamera(), framebuffer);
			SpriteRenderingSystem::OnRender(scene);
			ParticleSystem::OnRender(scene);
			context.Renderer->EndScene();
		}
	}

	void SceneManager::OnViewportResize(Scene &scene, const Box2D &viewport)
	{
		CameraSystem::OnViewportResize(scene, viewport);
	}

	void SceneManager::OnEvent(Scene &scene, Event &e)
	{
		NativeScriptSystem::OnEvent(scene, e);
	}
}