#pragma once

#include "Hazel/Core/Events/Event.h"
#include "Hazel/Core/Geometry/Box2D.h"
#include "Hazel/Core/Yaml/YamlSerializer.h"
#include "Hazel/Scene/Scene/Scene.h"
#include "Hazel/Scene/SceneManager/SceneManagerView.h"

namespace Hazel
{
	class ComponentSystem
	{
	private:
		SceneManagerView manager;

	public:
		virtual ~ComponentSystem() = default;

		SceneManagerView GetSceneManager() const
		{
			return manager;
		}

		void Attach(SceneManagerView manager)
		{
			this->manager = manager;
			OnAttach();
		}

		virtual void OnAttach()
		{
		}

		virtual void OnPlay(Scene &scene)
		{
		}

		virtual void OnUpdate(Scene &scene)
		{
		}

		virtual void OnRender(Scene &scene)
		{
		}

		virtual void OnViewportResize(Scene &scene, const Box2D &viewport)
		{
		}

		virtual void OnEvent(Scene &scene, Event &e)
		{
		}
	};
}