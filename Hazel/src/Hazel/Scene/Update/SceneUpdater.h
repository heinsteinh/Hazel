#pragma once

#include "Hazel/Scene/SceneManager/SceneManager.h"
#include "Hazel/Scene/Scene/Scene.h"

namespace Hazel
{
	class SceneUpdater
	{
	private:
		SceneManager *manager;

	public:
		SceneUpdater(SceneManager &manager)
			: manager(&manager)
		{
		}

		void OnPlay(Scene &scene)
		{
			manager->GetComponentSystems().OnPlay(scene);
		}

		void OnUpdate(Scene &scene)
		{
			manager->GetComponentSystems().OnUpdate(scene);
		}

		void OnViewportResize(Scene &scene, const Box2D &viewport)
		{
			manager->GetComponentSystems().OnViewportResize(scene, viewport);
		}

		void OnEvent(Scene &scene, Event &e)
		{
			manager->GetComponentSystems().OnEvent(scene, e);
		}
	};
}