#pragma once

#include "Hazel/Scene/Entity.h"

namespace Hazel
{
	class Script
	{
	private:
		Entity entity;
		Layer *layer = nullptr;

	public:
		virtual ~Script() = default;

		void Attach(Entity entity)
		{
			this->entity = entity;
			layer = entity.GetSceneContext().Layer;
		}

		void Detach()
		{
			entity = {};
			layer = nullptr;
		}

		template<typename ComponentType>
		ComponentType &GetComponent()
		{
			return entity.GetComponent<ComponentType>();
		}

		template<typename ComponentType>
		ComponentType *TryGetComponent()
		{
			return entity.TryGetComponent<ComponentType>();
		}

		float GetDeltaTime() const
		{
			return layer->GetDeltaTime();
		}

		const Window &GetWindow() const
		{
			return layer->GetWindow();
		}

		const Input &GetInput() const
		{
			return layer->GetInput();
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
	};
}