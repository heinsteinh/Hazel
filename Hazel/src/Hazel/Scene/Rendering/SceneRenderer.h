#pragma once

#include "Hazel/Scene/SceneManager/SceneManager.h"
#include "Hazel/Scene/Scene/Scene.h"

namespace Hazel
{
	class SceneRenderer
	{
	private:
		SceneManager *manager;

	public:
		SceneRenderer(SceneManager &manager)
			: manager(&manager)
		{
		}

		void RenderScene(Scene &scene)
		{
			auto &renderer = manager->GetRenderer();
			renderer.BeginScene(scene.GetCamera());
			manager->GetComponentSystems().OnRender(scene);
			renderer.EndScene();
		}
	};
}