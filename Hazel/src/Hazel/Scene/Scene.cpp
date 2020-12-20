#include "Scene.h"

#include "Hazel/Scene/Context/SceneRenderer.h"
#include "Hazel/Scene/Systems/CameraSystem.h"
#include "Hazel/Scene/Systems/NativeScriptSystem.h"
#include "Hazel/Scene/Systems/ParticleSystem.h"

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

	void Scene::OnGui()
	{
		NativeScriptSystem::OnGui(context);
	};
}