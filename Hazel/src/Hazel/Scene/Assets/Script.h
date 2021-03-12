#pragma once

#include "Hazel/Scene/Scene/Entity.h"
#include "Hazel/Scene/Scene/Scene.h"
#include "Hazel/Scene/SceneManager/SceneManagerView.h"

namespace Hazel
{
	class Script
	{
	private:
		std::string name;
		SceneManagerView manager;
		Scene *scene = nullptr;
		Entity entity;

	public:
		virtual ~Script() = default;

		const std::string &GetName() const
		{
			return name;
		}

		void SetName(const std::string &name)
		{
			this->name = name;
		}

		void Create(SceneManagerView manager, Scene &scene, Entity entity)
		{
			this->manager = manager;
			this->scene = &scene;
			this->entity = entity;
			OnCreate();
		}

		void Destroy()
		{
			OnDestroy();
			manager = {};
			scene = nullptr;
			entity = {};
		}

		SceneManagerView GetSceneManager() const
		{
			return manager;
		}

		Scene &GetScene() const
		{
			return *scene;
		}

		Entity GetEntity() const
		{
			return entity;
		}

		virtual void OnCreate()
		{
		}

		virtual void OnDestroy()
		{
		}

		virtual void OnUpdate()
		{
		}

		virtual void OnEvent(Event &e)
		{
		}

		virtual void OnGui()
		{
		}
	};
}