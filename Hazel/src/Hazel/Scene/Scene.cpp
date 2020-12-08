#include "Scene.h"

#include "Private/SceneRenderer.h"
#include "Hazel/Systems/CameraSystem.h"
#include "Hazel/Systems/NativeScriptSystem.h"
#include "Hazel/Systems/ParticleSystem.h"

namespace Hazel
{
	Scene::Scene(const SceneInfo &info)
		: context(info)
	{
	}

	void Scene::OnUpdate()
	{
		CameraSystem::OnUpdate(context);
		NativeScriptSystem::OnUpdate(context);
		ParticleSystem::OnUpdate(context);
	}

	void Scene::OnRender()
	{
		SceneRenderer::RenderScene(context);
	}

	void Scene::OnViewportResize(const Rectangle &viewport)
	{
		CameraSystem::OnViewportResize(context, viewport);
	}

	void Scene::OnEvent(Event &e)
	{
		NativeScriptSystem::OnEvent(context, e);
	}

	void Scene::OnImGuiRender()
	{
		NativeScriptSystem::OnImGuiRender(context);
	};
}